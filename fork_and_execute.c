#include "shell.h"

/**
 * fork_and_execute - Forks a new process and executes the command.
 * @input_line: the command string.
 */
void fork_and_execute(char *input_line)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: fork failed");
		fprintf(stderr, "Failed to create a new process. Exiting...\n");
		exit(1);
	}

	if (pid == 0)
	{
		execute_command(input_line);
		if (input_line != NULL)
		{
			free(input_line);
			input_line = NULL;
		}
		exit(0);
	}
	else
	{
		wait(&status);
	}
}
