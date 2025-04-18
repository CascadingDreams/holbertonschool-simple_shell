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
		char *argv[2];
		argv[0] = input_line;
		argv[1] = NULL;
		if (execve(input_line, argv, environ) == -1)
		{
			perror(input_line);
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}
