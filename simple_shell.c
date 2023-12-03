#include "main.h"

/**
 * run_shell - Run and Loop the shell.
 * Return: Nothing.
 */
void run_shell(void)
{
	char input[BUFFER_SIZE], *args[ARGS_MAX];
	int exit, iTokenized = 0, isInteractive = issatty(STDIN_FILENO);

	while (1)
	{
		if (isInteractive)
			interactive_shell(isInteractive);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			if (feof(stdin))
				break;
			else
			{
				perror("fgets");
				exit(EXIT_FAILURE);
				break;
			}
		}
		iTokenized = tokenizeInput(input, args);
		if (iTokenized > 0)
		{
			args[iTokenized] = NULL;
			if (strcmp(args[0], "exit") == 0)
				break; /* later handle exit */
			else if (strcmp(args[0], "env" == 0)
				break; /* later handle environment */
			else
				execute_command(args);
		}
	}

}
