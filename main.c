#include "main.h"

/**
 * main - Entry Point
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
