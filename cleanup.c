#include "shell.h"

/**
 * cleanup - frees memory allocated for the user input line.
 * @input_line: pointer to the dynamically allocated input string.
 *
 * This function is responsible for freeing the memory allocated by
 * getline() after the shell is done using the input. It helps
 * prevent memory leaks and clean program termination.
 */
void cleanup(char *input_line)
{
	free(input_line);
}
