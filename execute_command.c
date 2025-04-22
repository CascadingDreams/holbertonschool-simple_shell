#include "shell.h"

/**
 * execute_command - forks a child process to execute a given command.
 * @input_line: a string representing the full path to the executable command.
 *
 * This function creates a new process using fork(). In the child process,
 * it attempts to execute the provided command using execve(). If the command
 * fails (e.g., the file doesn't exist or isn't executable), it prints an
 * error message. The parent process waits for the child to complete before
 * returning.
 *
 * Return: 0 on success, -1 on fork failure.
 */
int execute_command(char *input_line)
{
	pid_t pid = fork();
	int status;

	if (pid < 0)
	{
		perror("fork failed");
		return (-1);
	}

	if (pid == 0)
	{
		char *argv[MAX_ARGS];
		int i = 0;
		char *token = strtok(input_line, " ");

		while (token != NULL && i < MAX_ARGS - 1)
		{
			argv[i++] = token;
			token = strtok(NULL, " ");
		}
		argv[i] = NULL;

		if (execve(argv[0], argv, environ) == -1)
		{
			perror(argv[0]);
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}