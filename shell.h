#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_ARGS 64

/**
 * struct shell_context - Contains shell state variables
 * @input_line: The current input line being processed
 * @exit_status: The current exit status
 */
typedef struct shell_context
{
	char *input_line;
	int exit_status;
} shell_ctx_t;

extern char **environ;

ssize_t read_input(char **lineptr, size_t *n);
void handle_sigint(int sig);
char *trim_space(char *str);
int parse_arguments(char *input, char **argv);
void fork_and_execute(char *input_line, char **envp, shell_ctx_t *ctx);
char *find_command_path(char *command, char **envp);
char *_getenv(char *name, char **env);
int main(int argc, char **argv, char **envp);
void check_exit_builtin(char *input, shell_ctx_t *ctx);
void run_shell_loop(char **envp);
void print_env(void);

#endif
