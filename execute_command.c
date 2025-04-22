#include "shell.h"

/**
 * execute_command - Executes a command with arguments by using execve().
 * @input_line: The command string to execute.
 *
 * Return: 0 on success, -1 on execve failure.
 */
int execute_command(char *input_line)
{
	char *argv[MAX_ARGS];

	parse_arguments(input_line, argv);

	if (execve(argv[0], argv, environ) == -1)
	{
		perror(argv[0]);
		return (-1);
	}

	return (0);
}
