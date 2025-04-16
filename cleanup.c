#include "shell.h"

void cleanup(char *input_line)
{
	free(input_line);
}
