#include "shell.h"

/**
 * fork_and_execute - Forks a new process and executes the command.
 * @input_line: the command string.
 * @envp: environ
 *
 * Return: void
 */

void fork_and_execute(char *input_line, char **envp)
{
	pid_t pid;
	int status;
	char *full_path, *argv[MAX_ARGS];

	parse_arguments(input_line, argv);
	if (!argv[0])
	{
		return;
	}

	full_path = find_command_path(argv[0], envp);
	if (!full_path)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		if (!isatty(STDIN_FILENO))
			exit(127);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		execve(full_path, argv, envp);
		perror("execve failed");
		exit(127);
	}
	else if (pid > 0)
	{
		wait(&status);
		if (!isatty(STDIN_FILENO))
			exit(1);
	}
	else
	{
		perror("fork failed");
		exit(1);
	}
	free(full_path);
}
