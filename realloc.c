#include "shell.h"

/**
 **_memset - populates a memory area with a specified byte value
 *@s: pointer to the memory area
 *@b: the byte to fill the memory *s with
 *@n: the number of bytes to be filled
 *Return: a pointer to the filled memory area (s)
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees memory for an array of strings
 * @pp: array of strings to be freed
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - adjusts the size of a memory block
 * @ptr: pointer to the previously allocated memory block
 * @old_size: size of the previous memory block in bytes
 * @new_size: size of the new memory block in bytes
 *
 * Return: a pointer to the adjusted memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
