# Simple Shell

This project is a basic UNIX command line interpreter written in C. It mimics the behavior of a simple shell. The shell reads user input, executes commands using `execve`, and displays the output, handling basic errors and EOF signals.

## Features

## Limitations

## Examples

### Interactive Mode:

```bash
$ ./hsh
#cisfun$ /bin/ls
AUTHORS  execute_command.c  hsh  main.c  read_input.c  shell.h
#cisfun$ /fake/command
./hsh: No such file or directory
#cisfun$ ^D
