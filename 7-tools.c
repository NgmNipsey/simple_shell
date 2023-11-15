#include "shell.h"

/**
 * _print_error - print error function.
 * @name: name
 * @cmd: pointer.
 * @index: index.
 *
 * Return: void.
 */
void _print_error(char *name, char *cmd, int index)
{
	char *idx, mssg[] = ": not found\n";

	idx = _atoi(index);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));

	free(idx);
}

/**
 * _atoi - atoi function to conver string into int.
 * @num: number.
 *
 * Return: double buffer.
 */
char *_atoi(int num)
{
	char buffer[20];
	int i = 0;

	if (num == 0)
		buffer[i++] = '0';
	else
	{
		while (num > 0)
		{
			buffer[i++] = (num % 10) + '0';
			num /= 10;
		}
	}
	buffer[i] = '\0';
	_reverse_string(buffer, i);
	return (_strdup(buffer));
}

/**
 * _reverse_string - reverse string function.
 * @dest: destination string.
 * @len: string length.
 *
 * Return: void.
 */
void _reverse_string(char *dest, int len)
{
	char tmp;
	int start = 0, end = len - 1;

	while (start < end)
	{
		tmp = dest[start];
		dest[start] = dest[end];
		dest[end] = tmp;
		start++;
		end--;
	}
}

/**
 * _free - function to free memory after use.
 * @command: pointer
 *
 * Return: Void.
 */
void _free(char **command)
{
	int i;

	if (!command)
		return;
	for (i = 0; command[i]; i++)
	{
		free(command[i]);
		command[i] = NULL;
	}
	free(command);
	command = NULL;
}
