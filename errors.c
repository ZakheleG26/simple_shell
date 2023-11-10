#include "shell.h"

/**
 *_eputs - prints the input string
 * @str: string to print
 *
 * Return: Ziltch
 */

void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes c character to stderr
 * @c: The character to be printed
 *
 * Return: If successful 1.
 * For an error, -1 is returned, and appropriately sets errno.
 */

int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writes the character c to given file descriptor
 * @c: The character that needs to be printed
 * @fd: Write in this filedescriptor
 *
 * Return: If successful 1.
 * For an error, -1 is returned, and appropriately sets errno.
 */

int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - print input string
 * @str: string to be printed
 * @fd: writes in this filedescriptor
 *
 * Return: the number of chars inserted
 */

int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
