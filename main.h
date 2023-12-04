#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define ARGS_MAX 64
#define EF EXIT_FAILURE
#define ES EXIT_SUCCESS

void run_shell(void);
void shell_work(char *args[]);
int tokenizeInput(char *input, char *args[]);
void strip_line(char *str);
void execute_command(char *args[], int *status);
void exit_shell(int status);

#endif /* __MAIN_H__ */
