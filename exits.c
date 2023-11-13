#include "shell.h"

/**
 **_strncpy - copy a string up to n characters
 *@dest: String copied to this destination
 *@src: Source string
 *@n: The character numbers to be copied
 *Return: Pointer to the destination string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - implement to locate a character in a string
 *@dest: String one
 *@src: String two
 *@n: Maximum number of bytes that can be used
 *Return: Pointer to concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - find the character in a string
 *@s: string that will be parsed
 *@c: the character to to be located
 *Return: A pointer to the memory area of str containing the character
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
