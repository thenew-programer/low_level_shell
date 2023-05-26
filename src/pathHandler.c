#include "shell.h"

/**
 * pathHandler - function that handle the path variable(PATH)
 * @arg: the command name e.g: ls
 * Return: a pointer to command path e.g: /bin/ls
 */

char  *pathHandler(char *arg)
{
	char *path, *token, *cmd, *pwd;
	unsigned int idx;
	struct stat sb;
	char buf[BUFF_SIZE];

	if (stat(arg, &sb) == 0)
		return (arg);
	idx = 0;
	while (__environ[idx])
	{
		if (strncmp(__environ[idx], "PATH", 4) == 0)
		{
			path = strdup(__environ[idx]);
			break;
		} idx++;
	}
	token = strtok(&path[5], ":");
	pwd = getcwd(buf, BUFF_SIZE), cmd = NULL;
	while (token)
	{
		chdir(token);
		if (stat(arg, &sb) == 0)
		{
			cmd = strdup(token);
			_strcat(cmd, arg);
			break;
		}
		token = strtok(NULL, ":");
	}
	chdir(pwd);
	free(path);
	return (cmd);
}
