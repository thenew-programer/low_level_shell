#include "../shell.h"

#define SUCCESS 1
#define FAILURE -1

int builtin(char *arg)
{
	builin_t bin[] = {
		{"exit", exiting},
		{"env", env},
		{NULL, NULL},
	};
	int x = 0;
	char *cmd = arg;
	void (*func)();
	while (bin[x].name)
	{
		if (strcmp(cmd, bin[x].name) == 0)
		{
			func = bin[x].func;
			func();
			
			return (SUCCESS);
		}
		x++;
	}
	return (FAILURE);
}

int main(void)
{
	builtin("env");
	printf("hello world\n");
	return EXIT_SUCCESS;
}
