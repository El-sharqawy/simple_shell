#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * executeCommand - function to execute commands
 * @command: an input string to execute
 * Return: executing results.
 */
int executeCommand(const char *command)
{
	int result;

	result = system(command);
	return (result);
}

/**
 * print_shell - print shell function
 * @isInt: is interactive
 * Return: Nothing.
 */
void print_shell(int isInt)
{
	if (isInt)
	{
		fprintf(stdout, "#simple_shell$ ");
		fflush(stdout);
	}
}

/**
 * main - Entry point
 * Return: ALways 0 (Success)
 */
int main(void)
{
	char input[512];
	size_t len = 0;
	int isInteractive = isatty(STDIN_FILENO);

	while (1)
	{
		if (isInteractive)
			print_shell(isInteractive);
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
				break;
			}
		}
		len = strlen(input);
		if (len > 0 && input[len - 1] == '\n')
		{
			input[len - 1] = '\0';
		}
		if (strcmp(input, "exit") == 0)
			break;
		executeCommand(input);
	}
	return (0)
}
