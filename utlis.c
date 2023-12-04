#include "main.h"

void strip_line(char *str)
{
	size_t len = strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0'; /* Replace the newline with null term */
}

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

void execute_command(char *args[], int *status)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		*status = EF;
		exit(EF);
	}
	else if (!pid)
	{
		execvp(args[0], args);
		perror("execvp");
		*status = EF;
		exit(EF);
	}
	else
	{
		waitpid(pid, status, 0);
	}
}

void exit_shell(int status)
{
	if (status == 0)
		exit(ES);
	else
		exit(EF);
}
