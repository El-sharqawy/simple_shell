#include "main.h"

/**
 * strip_spaces - strip leading and trailling whitespaces
 * @str: an input string to strip.
 * Return: Nothing.
 */
void strip_spaces(char *str)
{
	int start = 0, end = strlen(str) - 1;

	while (isspace(str[start]))
		str++;

	while ((end > start && isspace(str[end])))
		end--;

	str[end + 1] = '\0';
}

/**
 * interActiveExecute - function to print shell mark
 * @interactive: an input integer to check if interactive.
 * Return: Nothing.
 */
void interActiveExecute(int interactive)
{
	if (interactive)
	{
		fprintf(stdout, "#simple_shell$ ");
		fflush(stdout);
	}
}
/**
 * run_shell - Run and Loop the shell.
 * @env: an input enironment vars
 * Return: Nothing.
 */
void run_shell(char *env[])
{
	char input[BUFFER_SIZE], *args[ARGS_MAX];
	int iTokenized = 0, status = 0, isInteractive = isatty(STDIN_FILENO);

	while (1)
	{
		if (isInteractive)
			interActiveExecute(isInteractive);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			if (feof(stdin))
			{
				break;
			}
			else
			{
				perror("fgets");
				exit(EXIT_FAILURE);
			}
			break;
		}
		strip_spaces(input);
		strip_line(input);
		if (!strcmp(input, "exit") || !strcmp(input, "quit"))
		{
			exit_shell(status);
			break;
		}
		if (strcmp(input, "env") == 0)
		{
			print_environments(env);
			continue;
		}

		iTokenized = tokenizeInput(input, args);

		if (iTokenized > 0)
			execute_command(args, env, &status);
	}

}
