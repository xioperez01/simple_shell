#include "shell.h"

/**
  *create_path - Create a path to file
  *@input: File
  *Return: Path to file or file if not is necessary
  */


char **create_path(char **command)
{
	char *path, *bin = "/bin/";
	char *options[] = {"/bin/", "./"};
	int i;

	for (i = 0; i < 3; i++)
	{
		if (_strstr(command[0], options[i]) == 0)
			return (command);
	}

	if (i == 3)
	{
		path = _concat(bin, command[0]);
	}
	command[0] = path;
	return (command);

}
