#include "shell.h"

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
