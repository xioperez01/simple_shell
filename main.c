#include "shell.h"
/**
  *main - Create a own shell
  *@argc: characters entry count
  *@argv: description of characters of entry
  *Return: zero if success
 */

int main(void)
{
	char *input = NULL, *line_converted, **tokens, *path_command;
	char *search_program;
	int status, i = 0, type_command = 0;
	char s[] = "Error: File or description not found\n";

	do {
		if (isatty(STDIN_FILENO))
			write(1, "MAXIO~$ ", 8);

		input = read_line();
		line_converted = convert_to_null(input);
		printf("convirtió bien esto: %s\n\n", line_converted);
		tokens = split_line(line_converted, " ");
		printf("Partió bien esto: %s\n\n", *tokens);
		type_command = execute_builtins(tokens);
		if(type_command == -1)
		{
			printf("Encontró otro tipo de comando: %s\n\n", tokens[0]);

			path_command = _getenv("PATH=");
			printf("La ruta quedó: %s\n\n", path_command);
			search_program = _path(path_command, tokens[0]);
			
			if (search_program == NULL)
			{
				for(i = 0; s[i] != '\0'; i++)
				{
					_putchar(s[i]);
				}
			}
			else
				tokens[0] = search_program;
				status = exec_commands(tokens);
		}
		free(input);
		free(tokens);
	} while (status);

	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);

	return (0);
}
