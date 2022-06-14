#include "main.h"

/**
 * rev_str - Reverses the string array
 *
 * @str: Array To be Reversed
 * @len: Length Of Array
 *
 */

void rev_str(char *str, int len)
{
	int index;
	char tmp;

	for (index = 0; index < (len / 2); index++)
	{
		tmp = str[index];
		str[index] = str[(len - 1) - index];
		str[(len - 1) - index] = tmp;
	}
}

/**
 * calc_len_int - Determine Length Of Int
 *
 * @num: Given Int
 *
 * Return: Length Of Int
 *
 */

int calc_len_int(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}

	return (len);
}

/**
 * _itoa - Converts the given integer to character
 *
 * @num: The integer
 *
 * Return: A pointer to the converted string.
 *
 */

char *_itoa(unsigned int num)
{
	int len = 0, i = 0;
	char *str;

	len = calc_len_int(num);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	*str = '\0';
	while (num / 10)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	str[i] = (num % 10) + '0';
	rev_str(str, len);
	str[i + 1] = '\0';
	return (str);
}

/**
 * comment_handler - Handles comments in the inputed string.
 *
 * @str: A pointer to the input string.
 *
 * Return: A pointer to the input string ignoring all strings after
 * the # symbole.
 *
 */

void comment_handler(char *str)
{
	int index = 0;

	for (; str[index] != '\0'; index++)
	{
		if (str[index] == '#')
		{
			str[index] = '\0';
			break;
		}
	}
}

/**
 * my_getline - Reads standard input, Not same as standard getline().
 *
 * Return: A pointer to the input string.
 *
 */

char *my_getline()
{
	int size = 1024, index, r;
	char ch = 0;
	char *buffer = malloc(sizeof(char) * size);

	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}

	for (index = 0; ch != EOF && ch != '\n'; index++)
	{
		fflush(stdin);
		r = read(STDIN_FILENO, &ch, 1);
		if (r == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}

		buffer[index] = ch;

		if (buffer[0] == '\n')
		{
			free(buffer);
			return ("\0");
		}

		if (index >= size)
		{
			buffer = _realloc(buffer, size, size + 1);
			if (buffer == NULL)
				return (NULL);
		}
	}

	buffer[index] = '\0';
	comment_handler(buffer);
	return (buffer);
}
