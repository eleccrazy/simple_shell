#include "main.h"

/**
 * _strlen - Computes the length of a string.
 *
 * @str: The string whose length to be computed.
 *
 * Return: The length of the string.
 *
 */

int _strlen(char *str)
{
	int len = 0;

	if (!str)
		return (len);
	for (len = 0; str[len]; len++)
		;
	return (len);
}

/**
 * _strcpy - Copies the string pointed by src to des.
 *
 * @dest: The destination string
 * @src: The source string
 *
 * Return: A pointer to the destination string.
 *
 */

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	for (; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

/**
 * _strncpy - copies string from src to dest with a maximum bytes of n
 * @dest: a string argument to store the copied string
 * @src: a string argument to be copied
 * @n: the maximum number of bytes to be copied
 * Return: returns a string pointer dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	for (; src[i] != '\0'; i++)
		;
	for (j = 0; j < n; j++)
		dest[j] = src[j];
	for (j = i; j < n; j++)
		dest[j] = '\0';

	return (dest);

}

/**
 * _strcmp - compares two strings that it accepts
 * @s1: first string to be compared
 * @s2: second string to be compared
 * Return: returns 0 if they are equal, otherwise *s1 - *s1
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
  * _atoi - convets string to numbers
  * @s: a string argument to be converted
  * Return: returns integer value
  */

int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	do {

		if (*s == '-')
			sign *= -1;

		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');

		else if (num > 0)
			break;
	} while (*s++);

	return (num * sign);
}
