#include "shell.h"

/**
  *read_line - reads the command line
  *Return: Characters in the command line
  */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
		exit(0);
	else
		return (line);
}
