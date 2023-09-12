#include "include/main.h"

#define SUCCESS 1
#define FAILURE -1

/**
 * add_his - add a command to the history linked_list
 * @head: pointer to the first node of the history's ll
 * @command: command to be added
 * Return: 1 on Success and -1 on Failure
*/

void add_his(char *command) {
	history_t *new, *tmp;
	int i;

	new = (history_t *)malloc(sizeof(history_t));
	if (!new) {
		fprintf(stderr, RED "malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->command = strdup(command);
	new->next = NULL;
	new->prev = NULL;
	if (!history) {
		history = new;
		new->cmd_num = 0;
		return;
	}

	tmp = history;
	for (i = 0; tmp->next; i++) {
		tmp = tmp->next;
	}
	tmp->next = new;
	new->prev = tmp;
	new->cmd_num = ++i;
}


/**
 * free_his - free the history linked_list
 * @head: pointer to the head of the history's ll
 * Return: nothing
 */

void free_his(void) {
	history_t *head, *tmp;

	if (!history)
		return;
	
	head = history;
	while (head) {
		tmp = head->next;
		free(head->command);
		free(head);
		head = tmp;
	}
}

/**
 * _history_ - builtin command that prints the history of commands
 * Return: nothing
*/
void _history_(void) {
	history_t *tmp;

	if (!history) {
		fprintf(stderr, "No command has been executed yet\n");
		return;
	}
	tmp = history;
	while (tmp) {
		fprintf(stdout, "%.02u - %s\n", tmp->cmd_num, tmp->command);
		tmp = tmp->next;
	}
}
