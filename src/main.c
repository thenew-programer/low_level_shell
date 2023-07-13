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

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "-> ", 3);
		input = get_input();
		if (!input)
			continue;
		tokens = tokenize(input);
		if (builtin(tokens, input) == 0)
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
		execute(tokens, cmd);
		_free(3, input, tokens, cmd);
	}
	return (0);
}
