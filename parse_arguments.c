#include "shell.h"

/**
 * parse_arguments - Tokenizes the input string into arguments.
 * @input: The full command line input.
 * @argv: The array to store parsed arguments.
 *
 * Return: The number of arguments parsed.
 */
int parse_arguments(char *input, char **argv)
{
	char *token;
	int i = 0;

	token = strtok(input, " \t\r\n");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t\r\n");
	}
	argv[i] = NULL;

	return (i);
}
