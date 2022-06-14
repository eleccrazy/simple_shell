#include "main.h"

/**
 * _realloc - Reallocates a memory block.
 *
 * @ptr: void pointer
 * @old_size: Previous size
 * @new_size: The new size
 *
 * Return: A pointer to the reallocated memory
 *
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);

}

/**
 * custome_free - Free Array Of Char Pointer And Char Pointer
 * @cmd: A pointer to the array of characters
 * @line: A pointer to string
 *
 */

void custome_free(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * _memcpy - Copy Byte From Source To Destination
 *
 * @dest: Destination Pointer
 * @src: Source Pointer
 * @n: Size (How Much You Will Copy)
 *
 * Return: A pointer
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * fill_an_array - Fill An Array By Constant Byte
 *
 * @a: Void Pointer
 * @el: Int
 * @len: Length Int
 *
 * Return: Void Pointer
 */

void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

/**
 * _calloc -  Allocates memory for an array
 *
 * @size: Size
 *
 * Return: A pointer to the allocated memory
 *
 */

void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
	return (NULL);
	a = malloc(size);
	if (a == NULL)
	return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
