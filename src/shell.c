#include "shell.h"

/**
* main - entry point.
* @argc: argument counter.
* @argv: argument argument
* @envVar: env variables.
* Return: (0).
*/

int main(int argc, char **argv, char **envVar)
{
	if (argc == 1)
	{
		cmdPrompt(argv, envVar);
	}

	return (0);
}
