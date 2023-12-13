#include "main.h"

/**
 * main - Entry Point
 * @argc: number of arguments
 * @argv: an input arguments
 * @env: an input environments
 * Description: runs the shell loop.
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[], char *env[])
{
	(void)argc;
	(void)argv;

	run_shell(env);
	return (0);
}
