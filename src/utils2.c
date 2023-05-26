#include "shell.h"

/**
* _strlen - replace strlen
* @str: pointer to string
* Return: length
*/

size_t _strlen(char *str)
{
	size_t length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}
