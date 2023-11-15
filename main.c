#include "shell.h"

/**
 * main - simple shell manipulation.
 * @ac: argument count.
 * @av: Array of argument vectors.
 *
 *Return: Always 0.
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char **command = NULL;
	char *line = NULL;
	int index = 0, status = 0;
	(void)ac;

	while (1)
	{
		line = _get_line();
		if (line == NULL)
		{
			if (isatty(STDOUT_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		index++;

		command = _tokenizer(line);
		if (!command)
			continue;

		if (is_builtin(command[0]))
			handle_builtin(command);
		else
			status = _execute(command, av, index);
	}
	return (0);
}
