#include "shell.h"

/**
  *read_line - reads the command line
  *Return: Characters in the command line
  */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	int get;

	get = getline(&line, &bufsize, stdin);

	if (get == EOF)
	{
		free(line);
		write(1, "\n", 1);
		exit(0);
	}
	else
		return (line);
}
