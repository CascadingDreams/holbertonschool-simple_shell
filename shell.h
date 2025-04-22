#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;
ssize_t read_input(char **lineptr, size_t *n);
int execute_command(char *input_line);
void sigint_handler(int sig);

#endif
