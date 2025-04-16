#include "shell.h"

ssize_t read_input(char **lineptr, size_t *n)
{
	ssize_t input = getline(lineptr, n, stdin);

	if (input == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
	}
	return input;
}
