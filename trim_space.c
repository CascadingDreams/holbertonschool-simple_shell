#include "shell.h"

/**
 * trim_space - removes leading and trailing spaces from a string.
 * @str: the string to be trimmed.
 *
 * Return: a pointer to the trimmed string.
 */
char *trim_space(char *str)
{
	char *end;

	if (str == NULL)
		return NULL;

	while (*str == ' ' || *str == '\t')
		str++;

	if (*str == '\0')
		return str;

	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t'))
		end--;

	*(end + 1) = '\0';

	return str;
}
