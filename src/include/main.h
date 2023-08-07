#ifndef MAIN_H
#define MAIN_H

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

extern char **environ;

#define MAX_BUFFER 2048


/**
 * struct Builtin - struct that holds count of
 * built in command in shell;
 * @cmd: name of the command
 * @func: pointer to function
 */
typedef struct Builtin
{
	char *cmd;
	void (*func)(void);
} builtin_t;

/* Main functions*/
char *get_input();
char **tokenize(char *);
int execute(char **argv, char *full_cmd);
char *path_handler(char *arg);
int builtin(char **args, char *input);
void prompt(char *);

/* Utility functions*/
char* readline();
int _strlen(char *str);
int _strlen_input(char *str);
int get_tokens_count(char *input, char *delimiter);
char *get_path();
char *_strcat(char *, char *);
void _write_err(char *shell, char *err, char *cmd);
void _free(int count, ...);

/* Builtin functions*/
void _exit_(void);
void _env_(void);
void _chdir_(char *path);

#endif /* MAIN_H */
