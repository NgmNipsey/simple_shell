#include "shell.h"

/**
 * is_builtin - built_in function.
 * @av: pointer.
 *
 * Return: 0 & 1.
 */
int is_builtin(char *av)
{
	int i = 0;

	char *builtin[] = {"exit", "env", "setenv", "cd", NULL};

	while (builtin[i])
	{
		if (_strcmp(av, builtin[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
 * handle_builtin - function to handle builtin.
 * @av: double pointer.
 *
 * Return: void.
 */
void handle_builtin(char **av)
{
	if (_strcmp(av[0], "exit") == 0)
	{
		_free(av);
		exit(0);
	}
	else if (_strcmp(av[0], "env") == 0)
		print_env(av);
}

/**
 * print_env - function to print environment.
 * @cmd: double pointer.
 *
 * Return: void.
 */
void print_env(char **cmd)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	_free(cmd);
}
