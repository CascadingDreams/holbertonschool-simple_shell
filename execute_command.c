#include "shell.h"

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
		if (execve(input_line, argv, NULL) == -1)
		{
			perror("./shell");
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}
