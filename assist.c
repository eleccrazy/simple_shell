#include "main.h"

/**
 * _strncmp - Compare Amount (n) Of Characters Of Two Strings.
 *
 * @s1: A String.
 * @s2: A String.
 * @n: Amount Of Characters To Compare.
 *
 * Return: 1 If The Strings Don't Match Otherwise 0
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (1);
	}

	return (0);
}

/**
 * shell_exit - Exits the shell
 *
 * @cmd: Command to the shell
 * @buffer: use input
 * @filename: Program Name
 * @c: Count execution
 *
 */

void shell_exit(char **cmd, char *buffer, char *filename, int c)
{
	int exit_status, i = 0;

	if (cmd[1] == NULL)
	{
		free(buffer);
		free(cmd);
		exit(EXIT_SUCCESS);
	}

	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			error_print(filename, c, cmd);
			break;
		}
		else
		{
			exit_status = _atoi(cmd[1]);
			free(buffer);
			free(cmd);
			exit(exit_status);
		}
	}
}
