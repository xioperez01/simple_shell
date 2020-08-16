#include "shell.h"

/**
  *create_path - Create a path to file
  *@input: File
  *Return: Path to file or file if not is necessary
  */


char *create_path(char **command)
{
	char *path, *bin = "/bin/";
	char *options[] = {"/bin/", "cd", "exit", "help", "env", "./"};
	int i;

	for (i = 0; i < 7; i++)
	{
		if (_strstr(command[0], options[i]) == 0)
			return (command[0]);
	}

	if (i == 7)
		path = _concat(bin, command[0]);

	return (path);

}
