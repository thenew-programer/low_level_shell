#include "main.h"

/**
 * change_dir - implementation of the linux builtin function `cd`
 * @path: the path where you want to go
 * Return: 1 on success 0 on failure
 */

void _chdir_(char *path) {
  char pwd[1024];
  static char full_path[2048];

  /*
  if (strcmp(path, "~")) {
   chdir("/home/jos");
    return;
  }
   */

  if (path[0] == '/' &&
      !(path[1] == ':' && (path[2] == '\\' || path[2] == '/'))) {
    chdir(path);
    return;
  } else {
    getcwd(pwd, 1024);
    strcpy(full_path, pwd);
    strcat(full_path, "/");
    strcat(full_path, path);
    chdir(full_path);
  }
}
