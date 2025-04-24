#include <string.h>
#include <stdlib.h>

/**
 * check_exit_builtin - Checks if the input command is "exit" and exits the shell.
 * @input: The input string from the user (already trimmed).
 */
void check_exit_builtin(char *input)
{
	size_t len;
	int exit_code;

	if (input == NULL)
		return;

	len = strlen(input);

	if (len > 0 && input[len - 1] == '\n')
		input[len - 1] = '\0';
	
	if (strcmp(input, "exit") == 0)
	{
		exit_code = EXIT_SUCCESS;

		/*check for space and number after exit*/

		free(input); /* free memory before exiting*/
		exit(exit_code);
    }
}
