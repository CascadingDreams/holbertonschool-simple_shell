#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;
ssize_t read_input(char **lineptr, size_t *n);
int execute_command(char *input_line);
void cleanup(char *input_line);

#endif
