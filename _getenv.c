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
char *_getenv(char *name, char **envp)
{
        size_t len = strlen(name);
        int i;

        for (i = 0; envp[i]; i++)
        {
                if (strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
                        return (envp[i] + len + 1);
        }
        return (NULL);
}
