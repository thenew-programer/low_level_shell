#include "include/main.h"
#include <stdio.h>

/**
* main - function that execute the commands.
* @argc: argument count @argv: array containing the command and the options Return: 0 on success. */
history_t *history = NULL;

int main(int argc, char **argv)
{
	char *input, **tokens, *cmd;
	(void)argc;

	if (argc != 1) {
		fprintf(stderr, RED "Low Level Shell: We don't accept arguments here\n");
		exit(EXIT_FAILURE);
	}
	/* Print Version and Exit Information */
	puts("\t\t\t\t+---- ---- ---- ---- ---- ---- ---- ---- ---- ---- -- ---+");
	puts("\t\t\t\t|                                                        |");
	puts("\t\t\t\t|                                                        |");
	puts("\t\t\t\t|           Low Level Shell Version 0.0.0.1.4            |");
	puts("\t\t\t\t|                                                        |");
	puts("\t\t\t\t|                                                        |");
	puts("\t\t\t\t+--------------------------------------------------------+");
	puts("\n\n\n");
	signal(SIGINT, handle_signal);
	atexit(free_his);


	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			prompt("⚡", "➜");
		input = get_input();
		if (!input)
			continue;
		if (strcmp(input, "history") != 0)
			add_his(input);
		tokens = tokenize(input);
		if (builtin(tokens, input) == 1) {
			_free(2, input, tokens);
			continue;
		}
		cmd = path_handler(tokens[0]);
		if (cmd == NULL) {
			_write_err(argv[0], "command not found: ", tokens[0]);
			_free(2, input, tokens);
			continue;
		}
		if (execute(tokens, cmd) == -100)
			_write_err(argv[0], "An error occurred while executing -> ", tokens[0]);
		_free(3, input, tokens, cmd);
	}
	return (0);
}

void handle_signal(int signum) {
	if (signum == SIGINT) {
		putchar('\n');
		prompt("⚡", "➜");;
		fflush(stdout);
	}
}
