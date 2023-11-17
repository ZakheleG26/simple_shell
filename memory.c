#include "shell.h"

/**
 * bfree - releases a pointer and NULLIFIES address
 * @ptr: address of the pointer THAT WILL BE RELEASED
 *
 * Return: 1 for release, anything else 0.
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
