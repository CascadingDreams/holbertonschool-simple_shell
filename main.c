#include "shell.h"

/**
 * main - the entry point for the simple shell program.
 *
 * This function displays a prompt, reads user input, and forks a child process to
 * execute the command using execve(). The parent waits for the child to finish.
 * The loop continues until an EOF (Ctrl+D/C) is encountered, which causes the program
 * to terminate and free allocated memory.
 *
 * Return: 0 on success, exits with status 1 on failure.
 */
int main(void)
{
	int shell_running = 1;
	char *input_line = NULL;
	size_t input_len = 0;
	ssize_t user_input;
	pid_t pid;
	int status;

	signal(SIGINT, sigint_handler);

	while (shell_running)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("#cisfun$ ");
		}

		user_input = read_input(&input_line, &input_len);
		if (user_input == -1)
		{
			free(input_line);
			break;
		}

		input_line[strcspn(input_line, "\n")] = '\0';

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
			free(input_line);
			exit(0);
		}

		if (pid > 0)
		{
			wait(&status);
		}
	}
	free(input_line);
	return (0);
}