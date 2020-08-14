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
	char *line_converted;
	char **commands;
	int status;

	do {
		if (isatty(STDIN_FILENO))
			write(1, "MAXIO~$ ", 8);
		line = read_line();
		printf("leyó bn esto: %s\n\n", line);
		line_converted = convert_to_null(line);
		printf("convirtió bn esto: %s\n\n", line_converted);
		commands = split_line(line_converted);
		printf("separó bn esto: %s %s %s\n\n", commands[0], commands[1], commands[2]);
		status = exec_commands(commands);
		free(line);
		free(commands);
	} while (status);

	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);

	return (0);
}

