#include "main.h"

/**
 * handle_signal - Handles signal and prints a new prompt
 *
 * @sig: The signal
 *
 */

void handle_signal(__attribute__((unused)) int sig)
{
	signal(SIGINT, handle_signal);
	prints("\n$ ");
}

/**
 * split_buffer - splits a string into tokens and stores them
 * in a character array.
 *
 * @buffer: The string to be splitted.
 *
 * Return: A pointer to the array of characters.
 *
 */

char **split_buffer(char *buffer)
{
	int index = 0;
	char *token;
	char **array;

	if (buffer == NULL)
		return (NULL);

	array = malloc(sizeof(char) * 1024);
	if (array == NULL)
		return (NULL);

	token = my_strtok(buffer, "\n ");

	for (; token; index++)
	{
		array[index] = token;
		token = my_strtok(NULL, "\n ");
	}

	array[index] = NULL;

	return (array);
}

/**
 * excute_command - Executes simple shell command
 *
 * @cmd: The command
 * @b: The user input
 * @c: Counter
 * @filename: The name of the program
 *
 * Return: 0 on success, -1 on failure
 *
 */

int excute_command(char **cmd, char *b, int c, char *filename)
{
	pid_t pid;

	if (*cmd == NULL)
		return (-1);

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
			command_path(cmd);
		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, filename);
			free(b);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}

	else
		wait(NULL);

	return (0);
}

/**
 * main - Implements simple shell in both interactive and
 * non-interactive modes.
 *
 * @argc: The number of arguments that it accepts.
 * @argv: The array of pointers to the arguments supplied
 *
 * Return: Exit value by the status.
 *
 */

int main(int argc, char **argv)
{
	char *buffer;
	char **cmd;
	int c = 0;

	(void)argc;

	signal(SIGINT, handle_signal);

	while (1)
	{
		c++;
		if (isatty(STDIN_FILENO))
			prints("$ ");

		buffer = my_getline();

		if (buffer[0] == '\0')
			continue;

		cmd = split_buffer(buffer);

		if (_strcmp(cmd[0], "exit") == 0)
			shell_exit(cmd, buffer, argv[0], c);

		excute_command(cmd, buffer, c, argv[0]);

		custome_free(cmd, buffer);
	}

	return (0);
}
