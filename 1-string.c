#include "shell.h"

/**
 * _strdup - duplicate string.
 * @str: character string.
 *
 * Return: pointer to the string.
 */
char *_strdup(const char *str)
{
	char *ptr;
	int len = 0, i;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);
}

/**
 * _strcmp - compare two strings.
 * @s1: string one
 * @s2: string two.
 *
 * Return: number of bytes.
 */
int _strcmp(char *s1, char *s2)
{
	int tmp;

	tmp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		tmp = (int)*s1 - (int)*s2;
	}
	return (tmp);
}

/**
 * _strlen - calculate string length.
 * @s: character string.
 *
 *Return: length.
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * _strcat - concatenate strings.
 * @dest: destination string.
 * @src: source string.
 *
 * Return: pointer to destination string.
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*ptr)
		ptr++;
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = *src;
	return (dest);
}

/**
 * _strcpy - copy string.
 * @dest: destination string.
 * @src: source string.
 *
 * Return: pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
