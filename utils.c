#include "shell.h"

/**
* free2D - free a 2d array
* @arr: pointer to a 2d array
* Return: nothing.
*/

void free2D(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}


/**
* exiting - builtin function for exit
* Return: nothing
*/
void exiting(void)
{
	exit(0);
}

/**
* env - builtin function for env function.
* Description: prints out all the environment vars
* Return: nothing
*/
void env(void)
{
	int i = 0;

	while (__environ[i])
	{
		printf("%s\n", __environ[i]);
		i++;
	}
}

/**
* _write_err - replace printf
* @str: pointer to str
* Return: nothing
*/

void _write_err(char *str)
{
	write(STDERR_FILENO, str, _strlen(str));
	write(STDERR_FILENO, ": No such file or directory\n", 28);
}

/**
* _strcat - replace strcat from <string.h>
* @dest: destination string
* @src: source string
* Return: pointer to string
*/

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != 0)
		i++;
	while (src[j] != 0)
		j++;

	dest = realloc(dest, (i + j + 2) * sizeof(char));
	if (!dest)
		return (NULL);

	j = 0;
	dest[i++] = '/';
	while (src[j] != 0)
	{
		dest[i] = src[j];
		j++, i++;
	}
	dest[i] = 0;
	return (dest);
}
