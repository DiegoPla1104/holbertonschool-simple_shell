#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
char **tokeninput(char *input, char *delim);
void free_grid(char **grid);
char *_getenv(const char *str);
int executioner(char **path, char **arr);
char **tokenpath(char *input, char *delim);

#endif
