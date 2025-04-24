# Simple Shell

![Shell Logo](https://img.shields.io/badge/Simple-Shell-blue)
![C Language](https://img.shields.io/badge/Language-C-green)

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Built-in Commands](#built-in-commands)
- [Requirements](#requirements)
- [Installation](#installation)
- [Compilation](#compilation)
- [Usage](#usage)
  - [Interactive Mode](#interactive-mode)
  - [Non-Interactive Mode](#non-interactive-mode)
- [Examples](#examples)
- [Files and Functions](#files-and-functions)
- [Man Page](#man-page)
- [Authors](#authors)

## Description

This project is a simple implementation of a shell in C. The shell is a command-line interpreter that provides a user interface for Unix-like operating systems. It reads commands from standard input and executes them, bridging the gap between the user and the operating system kernel.

## Features

- Displays a prompt (`#cisfun$`) and waits for user input
- Executes commands with their arguments
- Handles the PATH to locate executables
- Supports absolute and relative paths for commands
- Manages process creation through fork and execve
- Waits for command completion before returning to the prompt
- Handles end-of-file condition (Ctrl+D)
- Gracefully handles interrupt signals (Ctrl+C)
- Trims whitespace from user input and filters non-printable characters
- Supports both interactive and non-interactive modes
- Provides error messages for commands not found

## Built-in Commands

The shell currently supports the following built-in commands:

- `exit`: Exit the shell
- `env`: Print the current environment variables

## Requirements

- Compiled on Ubuntu 20.04 LTS
- GCC compiler
- Compilation flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`

## Installation

Clone the repository to your local machine:

```bash
git clone https://github.com/yourusername/simple_shell.git
cd simple_shell
```

## Compilation

Compile all C files in the project:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
```

## Usage

### Interactive Mode

Run the shell in interactive mode:

```bash
./simple_shell
```

Once running, you'll see the prompt `#cisfun$` where you can enter commands.

### Non-Interactive Mode

Execute commands in non-interactive mode by piping them to the shell:

```bash
echo "command" | ./simple_shell
```

Or using a file containing commands:

```bash
./simple_shell < commands.txt
```

## Examples

### Basic Commands

```bash
$ ./simple_shell
#cisfun$ ls
file1.c file2.c README.md simple_shell
#cisfun$ pwd
/home/user/projects/simple_shell
#cisfun$ echo "Hello, World!"
Hello, World!
```

### Working with Directories

```bash
#cisfun$ mkdir test_directory
#cisfun$ cd test_directory
#cisfun$ pwd
/home/user/projects/simple_shell/test_directory
#cisfun$ cd ..
#cisfun$ pwd
/home/user/projects/simple_shell
```

### Command Execution with Arguments

```bash
#cisfun$ ls -la
total 56
drwxr-xr-x 2 user user  4096 Apr 22 10:00 .
drwxr-xr-x 6 user user  4096 Apr 22 09:50 ..
-rw-r--r-- 1 user user   220 Apr 22 09:50 .bash_logout
-rw-r--r-- 1 user user  3526 Apr 22 09:50 .bashrc
-rw-r--r-- 1 user user   675 Apr 22 09:50 .profile
-rw-r--r-- 1 user user  1124 Apr 22 10:00 _getenv.c
-rw-r--r-- 1 user user   275 Apr 22 10:00 check_exit.c
-rw-r--r-- 1 user user   842 Apr 22 10:00 find_command_path.c
-rw-r--r-- 1 user user   971 Apr 22 10:00 fork_and_execute.c
-rw-r--r-- 1 user user  1712 Apr 22 10:00 main.c
-rw-r--r-- 1 user user   308 Apr 22 10:00 parse_arguments.c
-rw-r--r-- 1 user user   224 Apr 22 10:00 print_env.c
-rw-r--r-- 1 user user   431 Apr 22 10:00 read_input.c
-rw-r--r-- 1 user user  1024 Apr 22 10:00 README.md
-rw-r--r-- 1 user user   554 Apr 22 10:00 shell.h
-rwxr-xr-x 1 user user 16384 Apr 22 10:00 simple_shell
-rw-r--r-- 1 user user   652 Apr 22 10:00 trim_space.c
```

### Using Built-in Commands

```bash
#cisfun$ env
USER=user
HOME=/home/user
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
...

#cisfun$ exit
$
```

### Absolute and Relative Paths

```bash
#cisfun$ /bin/ls
file1.c file2.c README.md simple_shell

#cisfun$ ./simple_shell
#cisfun$ exit
```

### Multiple Commands in Non-Interactive Mode

```bash
$ echo -e "ls\npwd\necho Hello\nexit" | ./simple_shell
file1.c file2.c README.md simple_shell
/home/user/projects/simple_shell
Hello
```

### Error Handling

```bash
#cisfun$ nonexistentcommand
./hsh: 1: nonexistentcommand: not found
```

## Files and Functions

| File | Description |
| --- | --- |
| `main.c` | Entry point for the shell program, handles signals and shell loop |
| `fork_and_execute.c` | Handles command execution by forking processes |
| `find_command_path.c` | Searches for commands in the PATH |
| `parse_arguments.c` | Tokenizes command line into arguments |
| `read_input.c` | Manages reading user input |
| `trim_space.c` | Handles whitespace trimming and character filtering |
| `check_exit.c` | Processes the built-in exit command |
| `print_env.c` | Implements the built-in env command |
| `_getenv.c` | Custom implementation of getenv function |
| `shell.h` | Header file with function prototypes |

### Main Functions

| Function | Description |
| --- | --- |
| `int main(void)` | Entry point - initializes shell and manages signal handlers |
| `void run_shell_loop(char **envp)` | Main shell loop - displays prompt, reads and processes commands |
| `void fork_and_execute(char *input_line, char **envp)` | Executes a command by forking a process |
| `char *find_command_path(char *command, char **envp)` | Searches for command in PATH directories |
| `int parse_arguments(char *input, char **argv)` | Tokenizes command line into arguments array |
| `ssize_t read_input(char **lineptr, size_t *n)` | Reads a line of input from the user |
| `char *trim_space(char *str)` | Removes leading/trailing whitespace and filters characters |
| `void handle_sigint(int signum)` | Handles interrupt signals (Ctrl+C) |
| `void check_exit_builtin(char *input)` | Checks and handles the exit command |
| `void print_env(void)` | Prints environment variables |
| `char *_getenv(char *name, char **env)` | Custom implementation to get environment variable values |

## Man Page

A manual page is available. To view it:

```bash
man ./man_1_simple_shell
```

## Authors

- [Ealise Wang](https://github.com/Ealise611) - <10503@holbertonstudents.com>
- [Sophie Kyi Oo](https://github.com/User10538) - <10538@holbertonstudents.com>
- [Sammy Hill](https://github.com/CascadingDreams) - <myallio94@gmail.com>

---

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## Acknowledgments

* Holberton School
