#ifndef SHELL_H
#define SHELL_H

#define BUFF_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>

/**
* struct Builtin - struct that handle the builtin functions pointer
* and there name.
* @name: the name
* @func: function pointer
*/
typedef struct Builtin
{
	char *name;
	void (*func)(void);
} builin_t;

void cmdPrompt(char **, char **);

char **commandHandler(const char *, char);

char *pathHandler(char *);

void executeCommand(char **, char **);

int builtin(char **);

void free2D(char **);

void free2Darr(char **, unsigned int count);

void exiting(void);

void env(void);

size_t _strlen(char *);

char *_strcat(char *, char *);

void _write_err(char *);
#endif
