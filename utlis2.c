#include "main.h"

/**
 * change_dir - function to change direction
 * @args: an input arguments.
 * Return: Nothing.
 */
void change_dir(char *args[])
{
	if (args[1] == NULL)
		fprintf(stderr, "cd: missing argument\n");
	else
		if (chdir(args[1]) != 0)
			perror("chdir");
}

/**
 * print_environments - a function to print environments
 * @env: an input environments variables
 * Return: Nothing.
 */
void print_environments(char *env[])
{
	int32_t i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
