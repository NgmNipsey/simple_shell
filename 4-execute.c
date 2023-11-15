#include "shell.h"

/**
 * _execute - function to execute given files.
 * @cmd: double pointer string.
 * @av: pointer sring.
 * @index: file index.
 *
 * Return: exit status of the file.
 */
int _execute(char **cmd, char **av, int index)
{
	pid_t child_id;
	int status;
	char *full_cmd = _getpath(cmd[0]);

	if (!full_cmd)
	{
		_print_error(av[0], cmd[0], index);
		_free(cmd);
		return (127);
	}

	child_id = fork();
	if (child_id == 0)
	{
		if (execve(full_cmd, cmd, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			_free(cmd);
		}
	}
	else
	{
		waitpid(child_id, &status, 0);
		_free(cmd);
		free(full_cmd), full_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
