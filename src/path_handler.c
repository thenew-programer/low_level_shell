#include "main.h"

/**
 * path_handler - function that handle the path variable(PATH)
 * @arg: the command name e.g: ls
 * Return: a pointer to command path e.g: /bin/ls
 */

char *path_handler(char *arg)
{
	char *path, *token;
	char *pwd = NULL, *cmd = NULL;
	struct stat sb;

	if (stat(arg, &sb) == 0)
		return (strdup(arg));
	path = get_path();
	token = strtok(&path[5], ":");
	pwd = getcwd(pwd, 0);
	while (token)
	{
		chdir(token);
		if (stat(arg, &sb) == 0)
		{
			cmd = _strcat(arg, token);
			break;
		}
		token = strtok(NULL, ":");
	}
	chdir(pwd);
	_free(2, path, pwd);
	return (cmd);
}

/**
 * get_path - retrieve the path variable (PATH)
 * Return: string that needs to be freed.
*/

char *get_path()
{
	unsigned int idx;
	char *path;

	idx = 0;
	while (environ[idx])
	{
		if (strncmp(environ[idx], "PATH", 4) == 0)
		{
			path = strdup(environ[idx]);
			break;
		} idx++;
	}
	return (path);
}
