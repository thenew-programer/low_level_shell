#include "main.h"

#define FAILURE -1
#define SUCCESS 1

/**
 * builtin - handle builtin commands like "exit"
 * @args: array of tokens, contains the command and its
 * argumemts
 * @input: string given by the user
 * Return: 1 On Success, -1 On failure
 *
 */

int builtin(char **args, char *input) {
  int i = 0;
  builtin_t builtin[] = {
      {"exit", _exit_},
      {"env", _env_},
      {"cd", NULL},
      {NULL, NULL},
  };

  while (builtin[i].cmd) {
    if (strcmp(builtin[i].cmd, args[0]) == 0) {
      if (strcmp(builtin[i].cmd, "exit") == 0) {
        _free(2, args, input);
		exit(EXIT_SUCCESS);
      } else if (strcmp(builtin[i].cmd, "cd") == 0) {
        if (args[1] == NULL) {
          _chdir_("/home/jos");
          return (SUCCESS);
        }
        _chdir_(args[1]);
        return (SUCCESS);
      } else {

        builtin[i].func();
        return (SUCCESS);
      }
    }
    i++;
  }
  return (FAILURE);
}
