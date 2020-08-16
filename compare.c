#include "shell.h"

/**
  *create_path - Create a path to file
  *@input: File
  *Return: Path to file or file if not is necessary
  */


char *create_path(char *input)
{
	char *str = input;
	char *path;
	char *bin = "/bin/";

	if (_strstr(str, "cd") == -1 && _strstr(str, "exit") == -1
			&& _strstr(str, "help") == -1 && _strstr(str, "env") == -1)
	{
		if (_strstr(str, "./") == 0)
		{
			return (str);
		}
		else if (_strstr(str, "/bin/") == 0)
		{
			return (str);
		}
		else
		{
			path = _concat(bin, str);
			return (path);
		}
	}
	else
	{
		return (str);
	}
}
