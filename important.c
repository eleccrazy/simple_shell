#include "main.h"

/**
 * check_delim - If the character mathes with any character in delimator
 *
 * @ch: The character
 * @d: The delimator
 *
 * Return: 1, if it matches, otherwise it returns 0
 *
 */

int check_delim(char ch, const char *d)
{
	int index = 0;

	while (d[index])
	{
		if (d[index] == ch)
			return (1);
		index++;
	}

	return (0);
}

/**
 * my_strtok - Takes tokens from a string like a standard strtok()
 *
 * @s: The string from which tokens are taken
 * @d: The delimator
 *
 * Return: A pointer to the token.
 *
 */

char *my_strtok(char *s, const char *d)
{
	int index = 0;
	static char *str1;
	static char *str2;

	if (s != NULL)
		str2 = s;
	str1 = str2;

	if (str1 == NULL)
		return (NULL);

	for (; str1[index]; index++)
	{
		if (check_delim(str1[index], d) == 0)
			break;
	}

	if (str2[index] == '\0' || str2[index] == '#')
	{
		str2 = NULL;
		return (NULL);
	}

	str1 = str2 + index;
	str2 = str1;

	for (index = 0; str2[index]; index++)
		if (check_delim(str2[index], d) == 1)
			break;
	if (str2[index] == '\0')
		str2 = NULL;
	else
	{
		str2[index] = '\0';
		str2 = str2 + index + 1;
		if (*str2 == '\0')
			str2 = NULL;
	}

	return (str1);
}

/**
 * _getenv - Gets the value of environment variable
 *
 * @name: The key
 *
 * Return: The value on success, otherwise NULL.
 *
 */

char *_getenv(char *name)
{
	size_t nl, vl;
	char *value;
	int i, x, j;

	nl = _strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], nl) == 0)
		{
			vl = _strlen(environ[i]) - nl;
			value = malloc(sizeof(char) * vl);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}
			j = 0;
			for (x = nl + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';
			return (value);
		}
	}

	return (NULL);
}

/**
 * make_path - Build Command
 *
 * @token: Excutable Command
 * @value: Dirctory Conatining Command
 *
 * Return: Parsed Full Path Of Command Or NULL Case Failed
 */

char *make_path(char *token, char *value)
{
	char *cmd;
	int len;

	len = _strlen(value) + _strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
		return (NULL);
	memset(cmd, 0, len);
	cmd = _strcat(cmd, value);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);

	return (cmd);
}

/**
 * command_path - Searches for executable command in path.
 *
 * @cmd: Command input.
 *
 * Return: 0 on success, and 1 on failure.
 *
 */

int command_path(char **cmd)
{
	char *key, *value, *c;
	struct stat buf;

	key = _getenv("PATH");
	value = my_strtok(key, ":");

	while (value != NULL)
	{
		c = make_path(*cmd, value);
		if (stat(c, &buf) == 0)
		{
			*cmd = _strdup(c);
			free(c);
			free(key);
			return (0);
		}

		free(c);
		value = my_strtok(NULL, ":");
	}

	free(key);

	return (1);
}
