#include "shell.h"

static char *input_line;

/**
 * handle_sigint - Handles Ctrl+C (SIGINT) signal.
 * @signum: Signal number.
 *
 * Frees input and exits the shell gracefully on interrupt.
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
 * run_shell_loop - Runs the main shell prompt loop.
 * @envp: The environment variables.
 */
void run_shell_loop(char **envp)
{
	char *trimmed_input;
	size_t input_len = 0;
	ssize_t user_input;
	int shell_running = 1;

	while (shell_running)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		user_input = read_input(&input_line, &input_len);
		if (user_input == -1)
		{
			free(input_line);
			input_line = NULL;
			break;
		}

		input_line[strcspn(input_line, "\n")] = '\0';
		trimmed_input = trim_space(input_line);

		if (*trimmed_input == '\0')
		{
			if (!isatty(STDIN_FILENO))
				exit(127);
			continue;
		}
		if (strcmp(trimmed_input, "env") == 0)
		{
			print_env();
			continue;
		}

		check_exit_builtin(trimmed_input);
		fork_and_execute(trimmed_input, envp);
	}

	free(input_line);
	input_line = NULL;
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
