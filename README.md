# Simple Shell

![Shell Logo](https://img.shields.io/badge/Simple-Shell-blue)
![C Language](https://img.shields.io/badge/Language-C-green)
![License](https://img.shields.io/badge/License-MIT-yellow)

## Table of Contents
- [Description](#description)
- [Features](#features)
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
- [License](#license)

## Description

This project is a simple implementation of a shell in C. The shell is a command-line interpreter that provides a user interface for Unix-like operating systems. It reads commands from standard input and executes them, bridging the gap between the user and the operating system kernel.

## Features

- Displays a prompt (`#cisfun$`) and waits for user input
- Executes commands with their arguments
- Handles the PATH to locate executables
- Manages process creation through fork and execve
- Waits for command completion before returning to the prompt
- Handles end-of-file condition (Ctrl+D)
- Gracefully handles interrupt signals (Ctrl+C)
- Trims whitespace from user input
- Supports both interactive and non-interactive modes

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

### Command Execution

```bash
#cisfun$ ls -la
total 56
drwxr-xr-x 2 user user  4096 Apr 22 10:00 .
drwxr-xr-x 6 user user  4096 Apr 22 09:50 ..
-rw-r--r-- 1 user user   220 Apr 22 09:50 .bash_logout
-rw-r--r-- 1 user user  3526 Apr 22 09:50 .bashrc
-rw-r--r-- 1 user user   675 Apr 22 09:50 .profile
-rw-r--r-- 1 user user  1124 Apr 22 10:00 execute_command.c
-rw-r--r-- 1 user user  2245 Apr 22 10:00 main.c
-rw-r--r-- 1 user user   461 Apr 22 10:00 read_input.c
-rw-r--r-- 1 user user  1024 Apr 22 10:00 README.md
-rw-r--r-- 1 user user   359 Apr 22 10:00 shell.h
-rwxr-xr-x 1 user user 16384 Apr 22 10:00 simple_shell
-rw-r--r-- 1 user user   397 Apr 22 10:00 trim_space.c
```

### Multiple Commands in Non-Interactive Mode

```bash
$ echo -e "ls\npwd\necho Hello" | ./simple_shell
file1.c file2.c README.md simple_shell
/home/user/projects/simple_shell
Hello
```

### Exit

```bash
#cisfun$ exit
$
```

## Files and Functions

| File | Description |
| --- | --- |
| `main.c` | Entry point for the shell program |
| `execute_command.c` | Handles command execution |
| `read_input.c` | Manages reading user input |
| `trim_space.c` | Handles whitespace trimming |
| `shell.h` | Header file with function prototypes |

### Main Functions

| Function | Description |
| --- | --- |
| `int main(void)` | Entry point - displays prompt, reads input, and processes commands |
| `int execute_command(char *input_line)` | Executes a command by forking a process |
| `ssize_t read_input(char **lineptr, size_t *n)` | Reads a line of input from the user |
| `char *trim_space(char *str)` | Removes leading and trailing whitespace from a string |
| `void handle_sigint(int signum)` | Handles interrupt signals (Ctrl+C) |

## Man Page

A manual page is available. To view it:

```bash
man ./man_1_simple_shell
```

## Authors

[Ealise Wang](https://github.com/Ealise611)
[Sophie Kyi Oo](https://github.com/User10538), 
[Sammy Hill](https://github.com/CascadingDreams)
## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## Acknowledgments

* Holberton School