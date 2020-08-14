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

	process = fork();
	/*Process CHILD*/
	if (process == 0)
	{
		printf ("se está ejecutando el hijo: %d \n", getpid());
		if (execve(commands[0], commands, NULL) == -1)
		{
			perror("child filed");
		}
		exit(2);
		/*printf("si esto sale es por el exit\n");*/
	}
	else if (process < 0)
		perror("fork failed");
	else
	{
		/*printf ("se está ejecutando el padre: %d\n", getpid());*/
		do {
			waitpid(process, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);

}
