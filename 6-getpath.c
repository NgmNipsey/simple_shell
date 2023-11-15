#include "shell.h"

/**
 * _getpath - get file path.
 * @cmd: pointer.
 *
 * Return: Null.
 */
char *_getpath(char *cmd)
{
	char *path_env, *full_cmd, *dir;
	struct stat state;
	int i;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &state) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}

	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);
	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + strlen(cmd) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, cmd);
			if (stat(full_cmd, &state) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd);
			full_cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
