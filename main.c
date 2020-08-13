#include "shell.h"
/**
  *main - Create a own shell
  *@argc: characters entry count
  *@argv: description of characters of entry
  *Return: zero if success
 */

int main(int __attribute__((unused)) argc, char __attribute__((unused)) **argv)
{
	char *line = NULL;
	char **commands;
	int status;
	

	do {
		if (isatty(STDIN_FILENO))
			write(1, "MAXIO~$ ", 8);
		line = read_line();
		printf("leyó bn esto: %s\n", line);
		commands = split_line(line);
		printf("separó bn esto: %s %s %s", commands[0], commands[1], commands[2]);
		status = exec_commands(commands);
		free(line);
		free(commands);
	} while (status);

	if(isatty(STDIN_FILENO))
		write(1, "\n", 1);

	return (0);
}

