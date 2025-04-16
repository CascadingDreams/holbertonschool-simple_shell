#include "shell.h"

int main(void)
{
	int shell_running = 1;
	char *input_line = NULL;
	size_t input_len = 0;
	ssize_t user_input;
	pid_t pid;
	int status;

	while (shell_running)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("#cisfun$ ");
		}

		user_input = read_input(&input_line, &input_len);
		if (user_input == -1)
		{
			cleanup(input_line);
			break;
		}

		input_line[strcspn(input_line, "\n")] = '\0';

		pid = fork();

		if (pid < 0)
		{
			perror("fork failed");
			exit(1);
		}

		if (pid == 0)
		{
			execute_command(input_line);
			exit(0);
		}

		if (pid > 0)
		{
			wait(&status);
		}
	}

	return 0;
}
