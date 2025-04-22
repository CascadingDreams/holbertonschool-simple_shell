#include "shell.h"

/**
 * _getenv - Retrieves the value of an environment variable.
 *
 * @name: The name of the environment variable to search for.
 * @env: The environment variables array.
 *
 * Searches through the `env` array for a matching environment variable name
 * and returns its value, or NULL if not found.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(char *name, char **env)
{
	int i;
	size_t len = strlen(name);

	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], name, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
	}
	return (NULL);
}
