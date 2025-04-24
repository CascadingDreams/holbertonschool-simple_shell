#include "shell.h"

static shell_ctx_t shell_ctx = {NULL, 0};

/**
 * handle_sigint - Handles Ctrl+C (SIGINT) signal.
 * @signum: Signal number.
 *
 * Frees input and exits the shell gracefully on interrupt.
 */
void handle_sigint(int signum)
{
	(void)signum;

	if (shell_ctx.input_line != NULL)
	{
		free(shell_ctx.input_line);
		shell_ctx.input_line = NULL;
	}

	write(STDOUT_FILENO, "\n", 1);
	exit(shell_ctx.exit_status);
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

	shell_ctx.input_line = NULL;
	shell_ctx.exit_status = 0;

	while (shell_running)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		user_input = read_input(&shell_ctx.input_line, &input_len);
		if (user_input == -1)
		{
			free(shell_ctx.input_line);
			shell_ctx.input_line = NULL;
			break;
		}

		shell_ctx.input_line[strcspn(shell_ctx.input_line, "\n")] = '\0';
		trimmed_input = trim_space(shell_ctx.input_line);

		if (*trimmed_input == '\0')
			continue;

		if (strcmp(trimmed_input, "env") == 0)
		{
			print_env();
			continue;
		}

		check_exit_builtin(trimmed_input, &shell_ctx);
		fork_and_execute(trimmed_input, envp, &shell_ctx);
	}

	free(shell_ctx.input_line);
	shell_ctx.input_line = NULL;
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

	return (shell_ctx.exit_status);
}
