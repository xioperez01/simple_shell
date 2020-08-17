#include "shell.h"

/**
  *execute_builtins - Execute the built_in for each case
  *@command: Command of the line command
  *Return: 0
  */

int execute_builtins(char **commands)
{
	char *f_cd = "cd";
	char *f_help = "help";
	char *f_exit = "exit";
	char *f_env1 = "env";

	/*In case the command is cd*/
	if (_strstr(commands[0], f_cd) == 0)
		return (_cd(commands));

	/*In case the command is help*/
	if (_strstr(commands[0], f_help) == 0)
		return (_help());

	/*In case the command is exit*/
	if (_strstr(commands[0], f_exit) == 0)
		return (_exit2());
	
	/*In case the command is env*/
	if (_strstr(commands[0], f_env1) == 0)
		return (_env(commands));

	return (-1);
}

/**
 *_cd - Directory change function
 *@arg: Arguments to _cd function
 *Return: 1
 */
int _cd(char **arg)
{
	char *s = "expected argument to cd";
	char *s2 = "No such file or directory";
	int i;

	if (arg[1] == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
			_putchar(s[i]);
		_putchar('\n');
	}
	else
	{
		if (chdir(arg[1]) != 0)
		{
			for (i = 0; s2[i] != '\0'; i++)
				_putchar(s[i]);
			_putchar('\n');
		}
	}
	printf("Ejecutó la función_cd\n\n");
	return (1);
}

/**
 *_help - Help function
 *@arg: Unused argument
 *Return: 0
 */
int _help(void)
{
	int i;
	char *s = "MAXIO Shell";
	char *s2 = "Type program names and arguments, and hit enter.";
	char *s3 = "The following commands are built in:";
	char *s4 = "cd", *s5 = "exit", *s6 = "env", *s7 = "help";
	char *s8 = "Use the man command for information on other programs.";

	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
	_putchar('\n');
	for (i = 0; s2[i] != '\0'; i++)
		_putchar(s2[i]);
	_putchar('\n');
	for (i = 0; s3[i] != '\0'; i++)
		_putchar(s4[i]);
	_putchar('\n');
	for (i = 0; s4[i] != '\0'; i++)
		_putchar(s5[i]);
	_putchar('\n');
	for (i = 0; s5[i] != '\0'; i++)
		_putchar(s5[i]);
	_putchar('\n');
	for (i = 0; s6[i] != '\0'; i++)
		_putchar(s6[i]);
	_putchar('\n');
	for (i = 0; s7[i] != '\0'; i++)
		_putchar(s7[i]);
	_putchar('\n');
	for (i = 0; s8[i] != '\0'; i++)
		_putchar(s8[i]);
	_putchar('\n');
	return (1);
}

/**
 *_exit2 - exits our command.
 *@arg: Our command.
 *Return: 0
 */
int _exit2(void)
{
	return (0);
}

/**
 *_env - Prints the current environ
 *@commands: Command line
 */

int _env(char **commands)
{
	int i;
	char *s = *environ;
	if (commands[1] != NULL)
	{
		return (0);
	}
	for (i = 0; s; i++)
	{
		write(STDIN_FILENO, s, _strlen(s));
		write(STDIN_FILENO, "\n", 1);
		s = *(environ + i);
	}
	return (0);
}


