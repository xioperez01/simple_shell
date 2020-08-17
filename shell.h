#ifndef SHELL_H
#define SHELL_H

/* libratries */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/* main functions prototypes */

char *read_line(void);
int str_len(char *str);
char *convert_to_null(char *line);
char **split_line(char *input);
int exec_commands(char **commands);
int _stat(const char *phat, struct stat *buf);
char **create_path(char **input);
char **find_built(char **commands);
/*int find_type_command(char **command);*/
int execute_builtins(char **command);

/* struct and prototypes to built_ins */

/*typedef struct base
{
	char *op;
	int (*f)(char **arg);
} built_t;
*/
int _cd(char **arg);
int _help(void);
int _exit2(void);
int _env(void);


/* aux_functions prototypes */

int _putchar(char c);
int _strstr(char *haystack, char *needle);
char *_concat(char *dest, char *src);
int _strlen(char *s);

#endif
