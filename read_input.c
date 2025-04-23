#include "shell.h"

/**
 * read_input - reads a line of input from the user.
 * @lineptr: pointer to a buffer where the input will
 * be stored.
 * @n: size of the buffer.
 *
 * This function uses the `getline` function to read
 * a line of input from the stdin.
 *
 * Return: the number of characters read, or -1 on
 * failure (e.g., EOF or error).
 */
ssize_t read_input(char **lineptr, size_t *n)
{
	ssize_t input = getline(lineptr, n, stdin);

	if (input == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	return (input);
}
