#include "shell.h"

/**
  *str_len - Return length of a string
  *@str: string to calculate the lenght
  *Return: length of string
  */
int str_len(char *str)
{
	int len;

	for (len = 0; *str != '\n'; len++)
	{
		str++;
	}
	return (len);
}

/**
  *convert_to_null - Create a copy of string,
  *reemplaces the character '\n' to '\0'
  *@line: string to copy and converted
  *Return: String copied
  */
char *convert_to_null(char *line)
{
	char *line_converted;
	int i;

	if (line == NULL)
		return (NULL);

	line_converted = malloc(sizeof(char) * str_len(line));

	if (line_converted == NULL)
		return (NULL);
	for (i = 0; i <= str_len(line); i++)
	{
		line_converted[i] = line[i];
		if (line[i] == '\n')
			line_converted[i] = '\0';
	}
	return (line_converted);
}
