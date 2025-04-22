#include "shell.h"

char *input_line = NULL;

void sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\nExiting cleanly...\n", 21);

	if (input_line != NULL)
	{
		free(input_line);
		input_line = NULL;
	}

	exit(0);
}
