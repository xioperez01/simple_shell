#include "shell.h"

/**
 *_final_path - create the final path of the executable
 *@path: PATH witouth PATH=
 *@new_command: Command with the character / at the beginning
 *Return: Final PATH
 */
char *_final_path(char *path, char *new_command)
{
	int i = 0, j = 5;
	char *whithout_path, **path_splited, *path_concat1;
	int _stat1 = 1;
	struct stat buff;

	whithout_path = malloc(sizeof(char) * (_strlen(path) - 4));

	if (whithout_path == NULL)
		return (NULL);

	for (i = 0; path[j] != '\0'; i++)
	{
		whithout_path[i] = path[j];
		j++;
	}

	whithout_path[i] = '\0';

	path_splited = split_line(whithout_path, ":");

	i = 0;

	while (_stat1 != 0)
	{
		if (path_splited[i] == NULL)
		{
			path_concat1 = NULL;
			return (path_concat1);
		}
		path_concat1 = _concat(path_splited[i], new_command);
		_stat1 = stat(path_concat1, &buff);

		if (_stat1 == 0)
			break;
		i++;
	}

	return (path_concat1);
}

/**
  *_path - Creates path if it is necesary
  *@full_path: String whit PATH enviroment variable
  *@commands: Program to execute
  *Return: Program whit path
  */

char *_path(char *full_path, char *commands)
{
	int i = 1, j = 0, _stat = 1;
	struct stat buffer;
	char *path_concat, *new_command;

	if (commands[0] == '/')
	{
		_stat = stat(commands, &buffer);
		if (_stat == 0)
			return (commands);
	}

	new_command = malloc(sizeof(char) * (_strlen(commands) + 1));

	if (new_command == NULL)
		return (NULL);

	new_command[0] = '/';

	for (i = 1; commands[j] != '\0'; i++)
	{
		new_command[i] = commands[j];
		j++;
	}

	path_concat = _final_path(full_path, new_command);
	return (path_concat);
}
