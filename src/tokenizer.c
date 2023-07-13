#include "main.h"

/**
* tokenize - splits the command that the user provide into
* multiple token
* @input: the command line provided by the user
* Return: array contains the tokens
*/

char **tokenize(char *input)
{
	char **argv, *tmpStr, *token;
	char delimiter[] = " \t";
	size_t count, idx;

	count = get_tokens_count(input, delimiter);
	argv = (char **)malloc(sizeof(char *) * count);
	if (!argv)
		return (NULL);

	tmpStr = input;
	token = strtok(tmpStr, delimiter);

	idx = 0;
	while (token)
	{
		argv[idx++] = token;
		token = strtok(NULL, delimiter);
	}
	argv[idx] = NULL;
	return (argv);
}
