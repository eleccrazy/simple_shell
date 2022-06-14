#include "main.h"

/**
 * _putchar - writes the character c to stdout
 *
 * @c: the character to print
 *
 * Return: 0 on success and -1 error and errno is set appropiately
 *
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - print a string by adding new line
 *
 * @str: A pointer to the string to be printed
 *
 */
void _puts(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
		_putchar(str[i]);

	_putchar('\n');
}

/**
 * prints - Prints the string to the standard output.
 *
 * @s: The string to be printed.
 *
 */

void prints(char *s)
{
	write(STDOUT_FILENO, s, _strlen(s));
}

/**
 * error_print - Prints custom error to the standard output
 * in the custome shell.
 *
 * @filename: The name of the program
 * @c: Error Count
 * @cmd: The command entered
 *
 */

void error_print(char *filename, int c, char **cmd)
{
	char *error_count;

	error_count = _itoa(c);
	prints(filename);
	prints(": ");
	prints(error_count);
	prints(": ");
	prints(cmd[0]);
	prints(": Illegal number: ");
	prints(cmd[1]);
	prints("\n");
	free(error_count);
}

/**
 * print_error - Display Error Based on Command and How Many Time Shell Looped
 *
 * @input: User input
 * @c: loop count
 * @filename: The name of the program
 *
 */

void print_error(char *input, int c, char *filename)
{
	char *error_count;

	error_count = _itoa(c);
	prints(filename);
	prints(": ");
	prints(error_count);
	prints(": ");
	prints(input);
	prints(": not found\n");
	free(error_count);
}
