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
	int i = 0;
	char *temp, *token, *path = "";

	if (env != NULL)
	{
		while (env[i] != NULL)
		{
			temp = malloc(strlen(env[i] + 1));
			strcpy(temp, env[i]);

			token = strtok(temp, "=");
			if (strcmp(token, name) == 0)
			{
				token = strtok(NULL, "=");
				if (token != NULL)
				{	
					path = malloc(strlen(token) + 1);
					strcpy(path, token);
				}
			}
			i++;
			free(temp);
		}
	}
	return (path);
}
