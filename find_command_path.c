#include "shell.h"

/**
 * find_command_path - Searches for the full path of a command in $PATH
 * @command: The command name (e.g., "ls")
 * Return: The full path (must be freed), or NULL if not found
 */

char *find_command_path(char *command)
{
	char *env_path, *path_copy, *dir;
	char full_path[256];

	if (command[0] == '/' || command[0] == '.')
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		return (NULL);
	}
	env_path = getenv("PATH");
	if (!env_path)
		return (NULL);

	path_copy = strdup(env_path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(full_path));
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
