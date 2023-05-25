#include "shell.h"

/**
 * _strlen - return string's length
 * @str: string
 *
 * Return: int
*/
int _strlen(char *str)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - compare 2 strings
 * @s1: string
 * @s2: string
 *
 * Return: int neg if s1 < s2 elseif s1>s2 pos else 0
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if first starts with prefix second
 * @haystack: first string
 * @needle: second string
 *
 * Return: address of haystack if exists or null
*/
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concates 2 strings
 * @dest: desination string
 * @src: source string
 *
 * Return: ptr to dest
*/
char *_strcat(char *dest, char *src)
{
	char *retn = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (retn);
}
