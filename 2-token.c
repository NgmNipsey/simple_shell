#include "shell.h"

/**
 * _tokenizer - get token function.
 * @s: string.
 *
 * Return: double pointer.
 */
char **_tokenizer(char *s)
{
	char **cmd = NULL;
	char *token = NULL, *tmp = NULL, delim[] = " \t\n";
	int i = 0, counter = 0;

	if (!s)
		return (NULL);
	tmp = _strdup(s);
	token = strtok(tmp, delim);
	if (token == NULL)
	{
		free(s), s = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		counter++;
		token = strtok(NULL, delim);
	}
	free(tmp), tmp = NULL;
	cmd = malloc(sizeof(char *) * (counter + 1));
	if (!cmd)
	{
		free(s);
		return (NULL);
	}
	token = strtok(s, delim);
	while (token)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	free(s);
	cmd[i] = NULL;
	return (cmd);
}
