#include "shell.h"

/**
 * sighandler - Controlador de la señal SIGINT (Ctl + C)
 * @sig: signal code.
 *
 * Return: Void
 */
void sighandler(int sig __attribute__((unused)))
{
	write(1, "\nMAXIO~$ ", 9);
}
