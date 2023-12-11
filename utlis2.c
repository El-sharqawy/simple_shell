#include "main.h"

void change_dir(char *args[])
{
	if (args[1] == NULL)
		fprintf(stderr, "cd: missing argument\n");
	else
		if (chdir(args[1]) != 0)
			perror("chdir");
}

void print_environments(char *env[])
{
	int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}	
