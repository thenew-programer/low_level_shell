#include "main.h"

/**
 * _strlen_input - function that count the len of input given by
 * the user.
 * @str: pointer to string containing the input
 * Return: length of input.
*/

int _strlen_input(char *str)
{
	int len = 0;

	while (*str != 10)
	{
		len++;
		str++;
	}
	return (len);
}

/**
 * _strlen - implementation of the strlen
 * @str: pointer to string
 * Return: length of string.
*/

int _strlen(char *str)
{
	int len = 0;

	while (*str != 0)
	{
		len++;
		str++;
	}
	return (len);
}

/**
* _write_err - replace printf
* @shell: shell name
* @err: the err
* @cmd: the command
* Return: nothing
*/

void _write_err(char *shell, char *err, char *cmd)
{
	write(STDERR_FILENO, shell, _strlen(shell));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, err, _strlen(err));
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, "\n", 1);
}

/**
* _strcat - implementation of strcat from <string.h>
* @s1: string
* @s2: string
* Return: pointer to string
*/

char *_strcat(char *s1, char *s2)
{
	char *cmd;
	int j = _strlen(s1);
	int i = _strlen(s2);

	cmd = malloc((i + j + 2) * sizeof(char));
	if (!cmd)
		return (NULL);

	i = 0;
	while (s2[i] != 0)
	{
		cmd[i] = s2[i];
		i++;
	}
	cmd[i++] = '/';
	j = 0;
	while (s1[j] != 0)
	{
		cmd[i] = s1[j];
		i++, j++;
	}
	cmd[i] = 0;
	return (cmd);
}

/**
 * get_tokens_count - count the length of tokens in
 * a string seperated by spaces or tabs
 * @input: the string
 * @delimiter: in most cases spaces
 * Return: numbers of tokens
*/
int get_tokens_count(char *input, char *delimiter)
{
	int count = 1;
	char *tmp_str;

	tmp_str = input;
	while (*tmp_str != 0)
	{
		if (delimiter[0] == *(tmp_str++) || delimiter[1] == *(tmp_str++))
			count++;
	}
	return (count++);
}
