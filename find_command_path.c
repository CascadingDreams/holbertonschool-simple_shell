#include "shell.h"

/**
 * find_command_path - Searches for the full path of a command in $PATH
 * @command: The command name (e.g., "ls")
 * @envp: The environment variables array.
 * Return: The full path (must be freed), or NULL if not found
 */

char *find_command_path(char *command, char **envp)
{
	char *path_env = getenv("PATH");
	char *path_copy, *dir, *full_path;
	struct stat st;
	(void)envp;

	if (!path_env || path_env[0] == '\0')
		return (NULL);

	path_copy = strdup(path_env);
	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
