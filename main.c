#include "shell.h"
/**
  *main - Create a own shell
  *@argc: characters entry count
  *@argv: description of characters of entry
  *Return: zero if success
 */

int main(int __attribute__((unused)) argc, char __attribute__((unused)) **argv)
{
	char *line = NULL, *line_converted, **commands, *path_command;
	int status, i;
	struct stat description;
	char s[] = "NOT FOUND";

	do {
		if (isatty(STDIN_FILENO))
			write(1, "MAXIO~$ ", 8);

		line = read_line();
		printf("leyó bn esto: %s\n\n", line);
		line_converted = convert_to_null(line);
		printf("convirtió bn esto: %s\n\n", line_converted);
		commands = split_line(line_converted);
		printf("separó bn esto: %s %s %s\n\n", commands[0], commands[1], commands[2]);
		path_command = create_path(commands);
		printf("está creando bn la ruta\n\n");
		if (stat(path_command, &description) == 0)
			status = exec_commands(commands);
		else
		{
			for(i = 0; s[i] != '\0'; i++)
				{
					_putchar(s[i]);
				}
			_putchar('\n');
		}
		free(line);
		free(commands);
	} while (status);

	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);

	return (0);
}

