#include "shell.h"

/**
 * find_command_path - Searches for the full path of a command in $PATH
 * @command: The command name (e.g., "ls")
 * @envp: The environment variables array.
 * Return: The full path (must be freed), or NULL if not found
 */

char *find_command_path(char *command, char **envp)
{
	char *path_env = _getenv("PATH", envp);
	char *path_copy, *dir, *full_path;
	struct stat st;

	if (command[0] == '/' || (command[0] == '.' && command[1] == '/'))
	{
		if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
			return (strdup(command));
		return (NULL);
	}

	if (!path_env || path_env[0] == '\0')
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

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
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
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
