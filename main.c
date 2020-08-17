#include "shell.h"
/**
  *main - Create a own shell
  *@argc: characters entry count
  *@argv: description of characters of entry
  *Return: zero if success
 */

int main(void)
{
	char *line = NULL, *line_converted, **commands, **path_command;
	int status, i = 0, type_command;
	struct stat description;
	char s[] = "NOT FOUND";

	do {
		if (isatty(STDIN_FILENO))
			write(1, "MAXIO~$ ", 8);

		line = read_line();
		line_converted = convert_to_null(line);
		printf("convirtió bien esto: %s\n\n", line_converted);
		commands = split_line(line_converted);
		printf("Partió bien esto: %s\n\n", *commands);
		type_command = execute_builtins(commands);
		if(type_command == -1)
		{
			printf("Encontró otro tipo de comando: %s\n\n", commands[0]);
			path_command = create_path(commands);
			printf("la ruta completa es: %s\n\n", path_command[0]);
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
		}
		free(line);
		free(commands);
	} while (status);

	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);

	return (0);
}
