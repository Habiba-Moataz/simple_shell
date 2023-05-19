#include "shell.h"

/**
 *ePuts - prints an input string
 * @st: the string to be printed
 *
 * Return: Nothing
 */
void ePuts(char *st)
{
	int i = 0;

	if (!st)
		return;
	while (st[i] != '\0')
	{
		ePutChar(st[i]);
		i++;
	}
}

/**
 * ePutChar - writes the character c to stderr
 * @x: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int ePutChar(char x)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (x == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (x != BUF_FLUSH)
		buf[i++] = x;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @x: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int putFd(char x, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (x == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (x != BUF_FLUSH)
		buf[i++] = x;
	return (1);
}

/**
 *_putsFd - prints an input string
 * @st: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int putsFd(char *st, int fd)
{
	int i = 0;

	if (!st)
		return (0);
	while (*st)
	{
		i += putFd(*st++, fd);
	}
	return (i);
}
