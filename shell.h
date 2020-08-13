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

/* prototypes */

char *read_line(void);
char **split_line(char *input);
int exec_commands(char **commands);
int sum_integers(int argc, char **argv[]);

#endif
