#include "main.h"

/**
* execute - function that execute the commands.
* @argv: array containing the command and the options
* @full_cmd: the full path of command returned from path_handler.
* Return: Nothing.
*/

int execute(char **argv, char *full_cmd)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
		return (-1);
	if (child_pid == 0)
	{
		if (execve(full_cmd, argv, environ) == -1)
			return (-100);
		else
			return (1);

	}
	else
		wait(&status);

	return (1);
}
