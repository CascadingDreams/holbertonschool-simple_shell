#include "shell.h"

/**
 * trim_space - removes leading and trailing spaces
 * from a string, and filters
 * non-printable characters.
 * @str: the string to be trimmed.
 *
 * Return: a pointer to the trimmed string.
 */
char *trim_space(char *str)
{
	char *end, *ptr;

	if (str == NULL)
		return (NULL);

	while (*str == ' ' || *str == '\t')
		str++;

	if (*str == '\0')
		return (str);

	ptr = str;
	while (*ptr != '\0')
	{
		if (*ptr < 32 || *ptr > 126)
		{
			*ptr = ' ';
		}
		ptr++;
	}

	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t' || *end < 32 || *end > 126))
		end--;

	*(end + 1) = '\0';

	return (str);
}
