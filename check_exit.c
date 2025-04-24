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

        if (strncmp(input, "exit", 4) == 0)
        {
                if (input_line != NULL)
                {
                        free(input_line);
                        input_line = NULL;
                }
                exit(exit_status);
        }
}
