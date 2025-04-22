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
 * main - the entry point for the simple shell program.
 *
 * This function displays a prompt, reads user input,
 * and forks a child process to execute the command
 * using execve(). The parent waits for the child to finish.
 * The loop continues until an EOF (Ctrl+D/C) is encountered,
 * which causes the program to terminate and free allocated memory.
 *
 * Return: 0 on success, exits with status 1 on failure.
 */
int main(int argc, char **argv, char **envp)
{
	int shell_running = 1;
	size_t input_len = 0;
	ssize_t user_input;
	char *trimmed_input;
	(void)argc;
	(void)argv;

	signal(SIGINT, handle_sigint);

	while (shell_running)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		user_input = read_input(&input_line, &input_len);
		if (user_input == -1)
		{
			if (input_line != NULL)
			{
				free(input_line);
				input_line = NULL;
			}
			break;
		}

		input_line[strcspn(input_line, "\n")] = '\0';

		trimmed_input = trim_space(input_line);
		if (*trimmed_input == '\0')
			continue;

		fork_and_execute(trimmed_input, envp);
	}

	if (input_line != NULL)
	{
		free(input_line);
		input_line = NULL;
	}

	return (0);
}
