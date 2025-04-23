#!/bin/bash

# This script tests how the shell handles empty PATH variable
# First, let's create a test file to feed into the shell
cat > test_commands.txt << EOF
ls
EOF

# Set PATH to empty string for the shell execution
echo "=== Running your shell with empty PATH ==="
env PATH="" ./hsh < test_commands.txt 2> shell_error.txt
SHELL_STATUS=$?

# Now run the same test with bash for comparison
echo -e "\n=== Running bash with empty PATH (for comparison) ==="
env PATH="" bash -c "ls" 2> bash_error.txt
BASH_STATUS=$?

# Show the outputs and exit codes
echo -e "\n=== Error output from your shell ==="
cat shell_error.txt

echo -e "\n=== Error output from bash ==="
cat bash_error.txt

echo -e "\n=== Exit status comparison ==="
echo "Your shell exit status: $SHELL_STATUS"
echo "Bash exit status: $BASH_STATUS"

# Check if the error message contains "not found" text
echo -e "\n=== Checking error message format ==="
if grep -q "not found" shell_error.txt; then
    echo "✓ Error message contains 'not found'"
else
    echo "✗ Error message does not contain 'not found'"
fi

# Check if the error message format matches "./hsh: 1: command: not found"
if grep -q "./hsh: 1: ls: not found" shell_error.txt; then
    echo "✓ Error message format matches expected pattern"
else
    echo "✗ Error message format does not match expected pattern"
    echo "  Expected: ./hsh: 1: ls: not found"
    echo "  Got: $(cat shell_error.txt)"
fi

# Cleanup
rm -f test_commands.txt shell_error.txt bash_error.txt

echo -e "\n=== Test complete ==="
