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
#include <errno.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define ARGS_MAX 64
#define EF EXIT_FAILURE
#define ES EXIT_SUCCESS
typedef unsigned int uint32_t;
typedef signed int int32_t;
typedef unsigned long int uint64_t;

extern char **environ;

void run_shell(char *env[]);
int tokenizeInput(char *input, char *args[]);
void strip_line(char *str);
void strip_spaces(char *str);
void execute_command(char *args[], char *env[], int *status);
void exit_shell(int status);
void print_environments(char *env[]);
void change_dir(char *args[]);
void interActiveExecute(void);

#endif /* __MAIN_H__ */
