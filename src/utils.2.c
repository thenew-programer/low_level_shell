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
