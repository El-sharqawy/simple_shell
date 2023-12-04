#include "main.h"

/**
 * run_shell - Run and Loop the shell.
 * Return: Nothing.
 */
void run_shell(void)
{
	char input[BUFFER_SIZE], *args[ARGS_MAX];
	int iTokenized = 0, isInteractive = isatty(STDIN_FILENO);

	while (1)
	{
		if (isInteractive)
		{
			fprintf(stdout, "#simple_shell$ ");
			fflush(stdout);
		}

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			if (feof(stdin))
				break;
			else
			{
				perror("fgets");
				exit(EF);
				break;
			}
		}
		iTokenized = tokenizeInput(input, args);

		if (iTokenized > 0)
		{
			args[iTokenized] = NULL;
			shell_work(args);
		}
	}

}

void shell_work(char *args[])
{
	int status = 0;

	if (strcmp(args[0], "exit") == 0)
		exit_shell(status);
	else if (strcmp(args[0], "env") == 0)
	{}
	else if (strcmp(args[0], "cd") == 0)
	{}
	else
		execute_command(args, &status);
}
