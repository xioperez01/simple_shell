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

/**
 * _concat - concatenate two strings
 * @dest: string to be appended to
 * @src: string to append
 * Return: resulting string
 */
char *_concat(char *dest, char *src)
{
	int i = 0, j = 0;
	int len1 = _strlen(dest) + _strlen(src);
	char *str_union = malloc(sizeof(char) * len1);

	if (!str_union)
		return (NULL);

	while (dest[i] != '\0')
	{
		str_union[i] = dest[i];
		i++;
	}

	while (src[j] != '\0')
	{
		str_union[i] = src[j];
		i++;
		j++;
	}

	return (str_union);
}

/**
 *_strlen - returns the length of a string.
 *@s: sting
 *Return: length
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
