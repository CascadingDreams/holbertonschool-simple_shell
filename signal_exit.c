#include "shell.h"

char *input_line = NULL;

void sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\nExiting cleanly...\n", 21);
	free(input_line);
	exit(0);
}
