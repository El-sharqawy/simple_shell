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

void execute_command(char *args[], char *env[], int *status)
{
	pid_t pid = fork();
	char path[256];
	char *prefix = "/bin/";

	strcpy(path, "/bin/");
	strcat(path, args[0]);

	if (args[0] == NULL || args[0][0] == '\0')
	{
		return;
    	}

	if (pid == -1)
	{
		perror("fork");
		*status = EXIT_FAILURE;
		exit(EXIT_FAILURE);
	}
	else if (!pid)
	{
		if (strncmp(args[0], prefix, strlen(prefix)) == 0)
			execve(args[0], args, env);
		else
			execve(path, args, env);
		/* execvp(args[0], args); */
		*status = EXIT_FAILURE;
		fprintf(stderr, "./hsh: %d: %s: not found\n", *status, args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, status, 0);
	}
}

void exit_shell(int status)
{
	if (status == 0)
		exit(EXIT_SUCCESS);

	else
		exit(2);
}
