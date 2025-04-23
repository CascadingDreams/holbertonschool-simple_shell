#include "shell.h"

static char *input_line;

/**
 * handle_sigint - Handles Ctrl+C (SIGINT) signal.
 * @signum: Signal number.
 */
void handle_sigint(int signum)
{
	if (signum > 0)
	{
		free(input_line);
	}
	exit(EXIT_SUCCESS);
}

/**
 * process_input - Trims and handles built-ins or commands.
 * @trimmed_input: The trimmed input line.
 * @envp: The environment variables.
 */
int process_input(char *trimmed_input, char **envp)
{
	char *argv[MAX_ARGS];
	int argc;

	if (*trimmed_input == '\0')
		return (0);

	argc = parse_arguments(trimmed_input, argv);

	if (argc == 0)
		return (0);

	if (strcmp(argv[0], "env") == 0)
	{
		print_env();
		return (0);
	}

	if (strcmp(argv[0], "exit") == 0)
	{
		if (argc > 1)
		{
			int status = atoi(argv[1]);
			free(input_line);
			exit(status);
		}
		else
		{
			free(input_line);
			exit(0);
		}
	}

	return (fork_and_execute(trimmed_input, envp));
}

/**
 * run_shell_loop - Runs the main shell prompt loop.
 * @envp: The environment variables.
 */
void run_shell_loop(char **envp)
{
	int shell_running = 1;
	char *trimmed_input;
	size_t input_len = 0;
	ssize_t user_input;
	int status = 0;

	while (shell_running)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		user_input = read_input(&input_line, &input_len);
		if (user_input == -1)
			break;

		input_line[strcspn(input_line, "\n")] = '\0';
		trimmed_input = trim_space(input_line);

		status = process_input(trimmed_input, envp);
		(void)status;
	}

	if (input_line)
	{
		free(input_line);
		input_line = NULL;
	}
}

/**
 * main - Entry point for the simple shell program.
 * @argc: The argument count.
 * @argv: The argument vector.
 * @envp: The environment variables.
 *
 * Return: 0 on success.
 */
int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	signal(SIGINT, handle_sigint);
	run_shell_loop(envp);

	return (0);
}
