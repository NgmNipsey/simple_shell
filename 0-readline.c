#include "shell.h"

/**
 * _get_line - get line function.
 *
 * Return: Number of bytes.
 */
char *_get_line(void)
{
	char *line = NULL;
	ssize_t num;
	size_t len = 0;

	if (isatty(STDOUT_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	num = getline(&line, &len, stdin);
	if (num == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
