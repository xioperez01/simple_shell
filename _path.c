#include "shell.h"

/**
  *_path - Creates path if it is necesary
  *@path_command: String whit PATH enviroment variable
  *@commands: Program to execute
  *Return: Program whit path
  */

char *_path(char *path_command, char *commands)
{
	char *without_path;
	char **path_splited;
	int i = 0, j = 0;
	struct stat buffer;
	char *path_concat;
	int _stat = 1;
	char *_commands;

	if(commands[0] == '/')
	{
		_stat = stat(commands, &buffer);
		if (_stat == 0)
			return (commands);
	}


	_commands = malloc(sizeof(char) * (_strlen(commands) + 1));
	if (_commands == NULL)
		return (NULL);

	_commands[0] = '/';
	i = 1;
	j = 0;

	for (i = 1; commands[i] != NULL; i++)
	{
		_commands[i] = commands[j];
		i++;
		j++;
	}


	without_path = malloc(sizeof(char) * (_strlen(path_command) - 4));
	if (without_path == NULL)
		return (NULL);

	i = 0;
	j = 5;

	for (i = 0; path_command[j] != '\0'; i++)
	{
		without_path[i] = path_command[j];
		j++;
	}
	without_path[i] = '\0';

	path_splited = split_line(without_path, ":");

	i = 0;
	_stat = 1;
	while (_stat != 0)
	{
		if(path_splited[i] == NULL)
		{
			path_concat = NULL;
			return (path_concat);
		}
		path_concat = _concat(path_splited[i], commands);
		_stat = stat(path_concat, &buffer);
		if(_stat == 0)
			break;
		i++;
	}

	return (path_concat);
}
