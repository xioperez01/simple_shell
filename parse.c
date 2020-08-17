#include "shell.h"
#define BUFF_SIZE 128

/**
  *get_input - Split the commands line
  *@input: line to split
  *Return: array of commands strings
  */

char **split_line(char *input)
{

	char *separator = " ";
	char *parsed;
	int index = 0;
	char **commands;

	if (input == NULL)
		return (NULL);

	commands = malloc(BUFF_SIZE * sizeof(char *));

	if (commands == NULL)
	{
		perror("malloc filed");
		exit(1);
	}

	parsed = strtok(input, separator);

	while (parsed != NULL)
	{
		commands[index] = parsed;
		index++;
		parsed = strtok(NULL, separator);
	}

	commands[index] = NULL;
	return (commands);
	free(commands);

}
