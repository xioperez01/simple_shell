#include "shell.h"
/**
  *main - Create a own shell
  *@argc: characters entry count
  *@argv: description of characters of entry
  *Return: zero if success
 */

int main(int __attribute__((unused)) argc, char __attribute__((unused)) **argv)
{
	char *line = NULL, *line_converted, **commands, **path_command;
	int status, i = 0;
	struct stat description;
	char s[] = "NOT FOUND";

	do {
		if (isatty(STDIN_FILENO))
			write(1, "MAXIO~$ ", 8);

		line = read_line();
		line_converted = convert_to_null(line);
		printf("que fastidio el martin\n");
		commands = split_line(line_converted);
		path_command = create_path(commands);
		printf("la ruta es: %s\n", path_command[0]);
		if (stat(path_command[0], &description) == 0)
		{
			printf("entra al if de stat\n");
			status = exec_commands(path_command);
		}
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
