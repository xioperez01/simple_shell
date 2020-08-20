#include "shell.h"

/**
 *exec_commands - Create a child process
 *@commands: Command to create process
 *Return: 1 to finish the process and add a new command by user
 */

int exec_commands(char **commands)
{
	pid_t process;
	int status;

	if (commands == NULL || commands[0] == NULL)
		perror("Error: Could not be executed");

	process = fork();
	/*Process CHILD*/
	if (process == 0)
	{
		if (execve(commands[0], commands, NULL) == -1)
		{
			perror("Error: ");
			exit(2);
		}

	}
	else if (process < 0)
		perror("Error: ");
	else
	{
		do {
			waitpid(process, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (EXIT_SUCCESS);
}
