#include <stdio.h>

/**
 * print_env - Prints the current environment variables.
 */
void print_env(void)
{
    extern char **environ;
    int i = 0;

    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
}
