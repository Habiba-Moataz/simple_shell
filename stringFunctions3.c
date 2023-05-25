#include "shell.h"

/**
 * _strchr - search char in string
 * @s: string
 * @c: character
 *
 * Return: ptr to s
*/
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 * _strncpy - copy first and second strings
 * @dest: desination string
 * @src: source string
 * @n: number of chars to be copied
 *
 * Return: ptr to concatenated str
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;

	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _strncat - copy first and second strings
 * @dest: desination string
 * @src: source string
 * @n: number of chars to be copied
 *
 * Return: ptr to concatenated str
*/
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}
