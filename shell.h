#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>
#include <signal.h>
#include <sys/stat.h>

#define MAX_ARGS 1024

extern char **environ;
ssize_t read_input(char **lineptr, size_t *n);
void handle_sigint(int sig);
char *trim_space(char *str);
int parse_arguments(char *input, char **argv);
int fork_and_execute(char *input_line, char **envp);
char *find_command_path(char *command, char **envp);
char *_getenv(char *name, char **env);
int main(int argc, char **argv, char **envp);
void check_exit_builtin(char *input);
void run_shell_loop(char **envp);
void print_env(void);
void execute_command(char *full_path, char **argv, char **envp);
void handle_input_error(char **argv);
int process_input(char *trimmed_input, char **envp);

#endif