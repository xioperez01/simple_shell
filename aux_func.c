#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *_strstr - compare two string
 *@haystack: input string
 *@needle: string to compare
 *Return: 0 on success or -1 if failed
 */
int _strstr(char *haystack, char *needle)
{
	int i = 0, j, x;

	if (needle[0] == '\0')
		return (-1);

	if (haystack[0] == needle[0])
	{
		while (haystack[i] != '\0' && needle[i] != '\0')
		{
			x = 0, j = 0;
			while (needle[j] != '\0')
			{
				if (haystack[x] == needle[j])
				{
					x++, j++;
				}
				else
				{
					return (-1);
				}
			}
			return (0);
		}
		i++;
	}
	return (-1);
}
