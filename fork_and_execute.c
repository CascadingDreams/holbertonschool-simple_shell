#include "shell.h"

/**
 * handle_input_error - Checks for invalid input and exits with error status.
 * @argv: Parsed arguments from the input line.
 */
void handle_input_error(char **argv)
{
	if (!argv[0] || argv[0][0] == '\0')
	{
		fprintf(stderr, "./hsh: 1: : not found\n");
		if (!isatty(STDIN_FILENO))
			exit(127);
	}
}

/**
 * execute_command - Executes a command in a child process.
 * @full_path: The full path of the command.
 * @argv: Arguments for the command.
 * @envp: Environment variables.
 */
void execute_command(char *full_path, char **argv, char **envp)
{
	if (execve(full_path, argv, envp) == -1)
	{
		perror("execve failed");
		free(full_path);
		exit(127);
	}
}

/**
 * fork_and_execute - Forks a process to execute the command.
 * @input_line: Input command string.
 * @envp: Environment variables.
 */
int fork_and_execute(char *input_line, char **envp)
{
	pid_t pid;
	int status, exit_status = 0;
	char *full_path, *argv[MAX_ARGS];

	parse_arguments(input_line, argv);

	if (!argv[0] || argv[0][0] == '\0')
		return (0);

	full_path = find_command_path(argv[0], envp);
	if (!full_path)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		if (!isatty(STDIN_FILENO))
			exit(127);
		return (127);
	}

	pid = fork();
	if (pid == 0)
	{
		execute_command(full_path, argv, envp);
	}
	else if (pid < 0)
	{
		perror("fork failed");
		free(full_path);
		if (!isatty(STDIN_FILENO))
			exit(1);
		return (1);
	}
	else
	{
		waitpid(pid, &status, 0);
		free(full_path);

		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
		else
			exit_status = 1;

		if (!isatty(STDIN_FILENO))
			exit(exit_status);
	}

	return (exit_status);
}