#include "shell.h"


/**
 * check_exit_builtin - Checks if the input command is
 * "exit" and exits the shell.
 * @input: The input string from the user (already trimmed).
 */
void check_exit_builtin(char *input)
{
	if (input == NULL)
                return;

        if (strcmp(input, "exit") == 0)
        {
                exit(exit_status);
        }
}
