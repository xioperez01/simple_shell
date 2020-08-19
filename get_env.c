#include "shell.h"

/**
  *_getenv - Gets an enviroment variable
  *@name: Enviroment variable To search
  *Return: Enviromental varible
  */

char *_getenv(char *name)
{
	char *name_var;
	int i, result = 0;

	if (name == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		result = _strstr(environ[i], name);
		if (result == 0)
			name_var = environ[i];
	}
	return (name_var);
}
