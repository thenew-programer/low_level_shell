#include "main.h"

#include <stdarg.h>

/**
 * _free - variadid function that takes argument
 * and frees them
 * @count: the number of vars you want to free
 * @...: arguments
 * Return: nothing
*/

void _free(int count, ...)
{
	va_list args;
	int i;
	char *ptr;

	va_start(args, count);
	for (i = 0; i < count; i++)
	{
		ptr = va_arg(args, char *);
		if (ptr)
			free(ptr);
	}
	va_end(args);

}

/**
 * _exit_ - exit
 * Return: nothing
 */
void _exit_(void)
{
	exit(0);
}

/**
 * _env_ - prints all the env variables
 * Return: nothing
*/
void _env_(void)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		i++;
	}
}

/**
 * readline - this function read a line for stdin
 * it will replace the readline function for editline lib
 * in the case of windows
 * @prompt: the string the user sees when he's typint a command
 * Return: address of input
 */

char* readline() {
	static char buffer[2048];
	char* cpy;
	fgets(buffer, 2048, stdin);
	cpy = malloc(strlen(buffer)+1);
	strcpy(cpy, buffer);
	cpy[strlen(cpy)-1] = '\0';
	return cpy;
}
