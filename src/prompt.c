#include "main.h"

/**
 * prompt - display the prompt and the actual dir the user in
 * @prompt: what the user wants to display
 * Return: nothing
 */

void prompt(char *prompt1, char *prompt2) {
  char pwd[2048];
  char *last_dir;
  char HOME_PATH[] = "jos";
  getcwd(pwd, 2048);
  last_dir = tokenize_prompt(pwd);
  if (strcmp(last_dir, HOME_PATH) == 0) {
    printf(YELLOW "%s" GREEN "%s" CYAN " ~ " RESET, prompt1, prompt2);
  } else {
    printf(YELLOW "%s" GREEN "%s" CYAN " %s " RESET, prompt1, prompt2, last_dir);
  }
}

/**
 * tokenize_prompt - tokenize the prompt and return the last dir
 * @path: path that will be tokenized
 * Return: last dir from the path
 */

char *tokenize_prompt(char *path) {
  char *token;
  char *last_dir;
  token = strtok(path, "/");
  while (token) {
    last_dir = token;
    token = strtok(NULL, "/");
  }
  return last_dir;
}
