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
	/*char **arguments;*/
	int status = 1;

	do {
		if (isatty(STDIN_FILENO))
			write(1, "MAXIO~$ ", 8);
		line = read_line();
		printf("bien hasta ahora: %s", line);
		/* arguments = _parse(line);*/
		/*status = _execute(args);*/
		free(line);
		/*free(arguments);*/
	} while (status);

	return (0);
}

