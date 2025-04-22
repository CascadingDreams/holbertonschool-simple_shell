#include "shell.h"

/**
 * fork_and_execute - Forks a new process and executes the command.
 * @input_line: the command string.
 */

void fork_and_execute(char *input_line, char **envp)
{
	pid_t pid;
	int status;
	char *full_path;
	char *argv[MAX_ARGS];

	parse_arguments(input_line, argv);
	if (!argv[0])
		return;

	full_path = find_command_path(argv[0], envp);
	if (!full_path)
	{
		fprintf(stderr, "%s: command not found\n", argv[0]);
		return;
	}

	pid = fork();
	if (pid < 0)
	{
		perror("Error: fork failed");
		fprintf(stderr, "Failed to create a new process. Exiting...\n");
		free(full_path);
		exit(1);
	}

	if (pid == 0)
	{
		execve(full_path, argv, envp);
		perror("execve failed");
		free(full_path);
		exit(1);
	}
	else
	{
		wait(&status);
		free(full_path);
	}
}
