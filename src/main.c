#include "main.h"
#include <stdio.h>

/**
* main - function that execute the commands.
* @argc: argument count
* @argv: array containing the command and the options
* Return: 0 on success.
*/


char *input, **tokens, *cmd;

int main(int argc, char **argv)
{
	(void)argc;
	if (argc != 1) {
		perror("Low Level Shell: We don't accept arguments here");
		exit(EXIT_FAILURE);
	}
	/* Print Version and Exit Information */
	puts("			+---- ---- ---- ---- ---- ---- ---- ---- ---- ---- -- ---+");
	puts("			|			Low Level Shell Version 0.0.0.1.4			 |");
	puts("			+--------------------------------------------------------+");
	puts("\n\n\n");
	signal(SIGINT, handle_signal);


	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			prompt("⚡->");
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

void handle_signal(int signum) {
	if (signum == SIGINT) {
		putchar('\n');
		prompt("⚡->");
		fflush(stdout);
	}
}
