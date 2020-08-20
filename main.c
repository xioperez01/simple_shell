#include "shell.h"
/**
  *main - Create a own shell
  *Return: zero if success
 */

int main(void)
{
	char *input = NULL, *line_converted, **tokens, *path_command;
	char *search_program;
	int status, i = 0;
	char s[] = "Error: File or description not found\n";

	signal(SIGINT, sighandler);
	do {
		if (isatty(STDIN_FILENO))
			write(1, "MAXIO~$ ", 8);

		input = read_line();
		line_converted = convert_to_null(input);
		tokens = split_line(line_converted, " ");
		status = execute_builtins(tokens);
		if (status == EXIT_FAILURE)
		{
			path_command = _getenv("PATH=");
			search_program = _path(path_command, tokens[0]);

			if (search_program == NULL)
			{
				for (i = 0; s[i] != '\0'; i++)
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
		free(search_program);
	} while (status);

	return (EXIT_SUCCESS);
}
