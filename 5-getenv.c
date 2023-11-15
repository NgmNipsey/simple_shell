#include "shell.h"

/**
 * _getenv - get environment.
 * @variable: pointer variable.
 *
 * Return: Null.
 */
char *_getenv(char *variable)
{
	char *value, *tmp, *key, *env;
	int i = 0;

	while (environ[i])
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp);
		tmp = NULL;
		i++;
	}
	return (NULL);
}
