#include "shell.h"

/**
 * fork_and_execute - Forks a new process and executes the command.
 * @input_line: the command string.
 * @envp: environ
 * @ctx: Pointer to the shell context structure containing state variables.
 *
 * Return: void
 */
void fork_and_execute(char *input_line, char **envp, shell_ctx_t *ctx)
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
		ctx->exit_status = 127;
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		execve(full_path, argv, envp);
		perror("execve failed");
		free(full_path);
		exit(127);
	}
	else if (pid < 0)
	{
		perror("fork failed");
		free(full_path);
		return;
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			ctx->exit_status = WEXITSTATUS(status);
		free(full_path);
	}
}
