#include "main.h"

/**
* main - function that execute the commands.
* @argc: argument count
* @argv: array containing the command and the options
* Return: 0 on success.
*/



int main(int __attribute((unused)) argc, char **argv)
{
	char *input, **tokens, *cmd;
	/* Print Version and Exit Information */
	puts("Low Level Shell Version 0.0.0.1.4");
	puts("Press Ctrl+c to Exit\n\n\n");


	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			prompt("-> ");
		input = get_input();
		if (!input)
			continue;
		tokens = tokenize(input);
		if (builtin(tokens, input) == 1)
		{
			_free(2, input, tokens);
			continue;
		}
		cmd = path_handler(tokens[0]);
		if (cmd == NULL)
		{
			_write_err(argv[0], "command not found: ", tokens[0]);
			_free(2, input, tokens);
			continue;
		}
		if (execute(tokens, cmd) == -100)
		{
			_write_err(argv[0], "An error occurred while executing -> ", tokens[0]);
		}
		_free(3, input, tokens, cmd);
	}
	return (0);
}
