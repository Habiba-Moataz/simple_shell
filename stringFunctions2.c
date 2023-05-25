#include "shell.h"

/**
 * _strcpy - copy first and second strings
 * @dest: desination string
 * @src: source string
 *
 * Return: ptr to dest
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplicates string
 * @str: string
 *
 * Return: ptr to str
*/
char *_strdup(const char *str)
{
	int length = 0;
	char *retn;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	retn = malloc(sizeof(char) * (length + 1));
	if (!retn)
		return (NULL);
	for (length++; length--;)
		retn[length] = *--str;
	return (retn);
}

/**
 * _puts - print string
 * @str: string
 *
 * Return: doesn't return
*/
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes char to standard output
 * @c: char
 *
 * Return: 1 if error occured return -1
*/
int _putchar(char c)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buffer[i++] = c;
	return (1);
}
