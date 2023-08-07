#include "main.h"


/**
 * prompt - display the prompt and the actual dir the user in
 * @prompt: what the user wants to display
 * Return: nothing
 */

void prompt(char *prompt) {
  char pwd[2048];
	char HOME_PATH[] = "/home/jos";
  char *tmp;
  getcwd(pwd, 2048);
  tmp = strstr(pwd, HOME_PATH);
  if (strcmp(pwd, HOME_PATH) == 0) {
    printf(GREEN "~" RED " %s " RESET, prompt);
  } else if (tmp) {
    printf(GREEN "~%s" RED " %s " RESET, tmp, prompt);
  } else {
    printf(GREEN "%s" RED " %s " RESET, pwd, prompt);
  }
}
