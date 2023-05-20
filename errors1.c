#include "shell.h"

/**
 * errAtoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int errAtoi(char *c)
{
	int i = 0;
	unsigned long int result = 0;

	if (*c == '+')
		c++;  /* TODO: why does this make main return 255? */
	for (i = 0;  c[i] != '\0'; i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			result *= 10;
			result += (c[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * printError - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void printError(info_t *info, char *est)
{
	ePuts(info->fname);
	ePuts(": ");
	printD(info->line_count, STDERR_FILENO);
	ePuts(": ");
	ePuts(info->argv[0]);
	ePuts(": ");
	ePuts(estr);
}

/**
 * printD - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int printD(int input, int fd)
{
	int (*putChar)(char) = putChar;
	int i, count = 0;
	unsigned int abs, current;

	if (fd == STDERR_FILENO)
		putChar = ePutChar;
	if (input < 0)
	{
		abs = -input;
		putChar('-');
		count++;
	}
	else
		abs = input;
	current = abs;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (abs / i)
		{
			putChar('0' + current / i);
			count++;
		}
		current %= i;
	}
	putChar('0' + current);
	count++;

	return (count);
}

/**
 * convertNumber - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convertNumber(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * removeComments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void removeComments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
