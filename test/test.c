#include "../shell.h"

int main(void)
{
	char *cmd;
	char str[] = "clear";
	cmd = pathHandler(str);
	printf("cmd: %s\n", cmd);
	free(cmd);
	return EXIT_SUCCESS;
}
