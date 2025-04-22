#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_ARGS 64

extern char **environ;
ssize_t read_input(char **lineptr, size_t *n);
int execute_command(char *input_line);
void handle_sigint(int sig);
char *trim_space(char *str);
int parse_arguments(char *input, char **argv);
void fork_and_execute(char *input_line);

#endif
