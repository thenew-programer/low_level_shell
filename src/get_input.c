#include "main.h"

/**
 * get_input - handle the input given by the user
 * Return: pointer to the input
*/
char *get_input(void)
{
	char *input = NULL;
	size_t n = 0;

	if (getline(&input, &n, stdin) == -1)
	{
		free(input);
		exit(EXIT_FAILURE);
	}
	if (input[0] == '\n')
	{
		free(input);
		return (NULL);
	}
	input[_strlen_input(input)] = '\0';
	return (input);
}
