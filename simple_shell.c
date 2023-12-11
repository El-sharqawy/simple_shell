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
 * run_shell - Run and Loop the shell.
 * Return: Nothing.
 */
void run_shell(char *env[])
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
				exit(EXIT_FAILURE);
				break;
			}
		}
		strip_spaces(input);
		strip_line(input);
		if (input[0] == '\0')
			continue;
		iTokenized = tokenizeInput(input, args);

		if (iTokenized > 0)
		{
			args[iTokenized] = NULL;
			shell_work(args, env);
		}
	}

}

void shell_work(char *args[], char *env[])
{
	int status = 0;

	if (!strcmp(args[0], "exit") || !strcmp(args[0], "quit"))
		exit_shell(status);
	else if (strcmp(args[0], "env") == 0)
		print_environments(env);
	else if (strcmp(args[0], "cd") == 0)
		change_dir(args);
	else
	{
		execute_command(args, env, &status);
	}
}
