#include "main.h"

/**
 * strip_line - function to strip new line
 * @str: an input string to strip.
 * Return: Nothing.
 */
void strip_line(char *str)
{
	size_t len = strlen(str);

	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0'; /* Replace the newline with null term */
}

/**
 * tokenizeInput - function to tokenize input before executing it
 * @input: an input character
 * @args: an input string
 * Return: tokens count.
 */
int tokenizeInput(char *input, char *args[])
{
	char *token;
	int tokenCount = 0;

	token = strtok(input, " ");
	while (token != NULL && tokenCount < ARGS_MAX - 1)
	{
		strip_line(token);
		args[tokenCount++] = token;
		token = strtok(NULL, " ");
	}
	args[tokenCount] = NULL;

	return (tokenCount);
}

/**
 * execute_command - function to execute shell commands
 * @args: an input argument
 * @env: an input environments
 * @status: an input status
 * Return: Nothing.
 */
void execute_command(char *args[], char *env[], int *status)
{
	pid_t pid;

	if (args[0] == NULL || args[0][0] == '\0')
		return;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		*status = EXIT_FAILURE;
		exit(EXIT_FAILURE);
	}
	else if (!pid)
	{
		execvp(args[0], args);
		*status = EXIT_FAILURE;
		fprintf(stderr, "./hsh: %d: %s: not found\n", 1, args[0]);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, status, 0);
}

/**
 * exit_shell - function to exit the shell.
 * @status: exit status
 * Return: Nothing.
 */
void exit_shell(int status)
{
	if (status == 0)
		exit(EXIT_SUCCESS);

	else
		exit(2);
}
