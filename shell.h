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

/* global variable */

extern char **environ;

/* main functions prototypes */

char *read_line(void);
int str_len(char *str);
char *convert_to_null(char *line);
char **split_line(char *input, char *separator);
int exec_commands(char **commands);
int _stat(const char *phat, struct stat *buf);
char **find_built(char **commands);
char *_path(char *path_command, char *commands);
char *_getenv(char *name);
char *_final_path(char *path, char *new_command);

/* Builtins prototypes */

int execute_builtins(char **command);
int _cd(char **arg);
int _help(void);
int _exit2(void);
int _env(char **commands);

/* Sighandler prototype */

void sighandler(int sig __attribute__((unused)));

/* aux_functions prototypes */

int _putchar(char c);
int _strstr(char *haystack, char *needle);
char *_concat(char *dest, char *src);
int _strlen(char *s);

#endif
