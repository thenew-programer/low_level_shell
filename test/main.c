#include "../shell.h"

int main(void)
{
	char cmd[] = "/bin/cp";
	struct stat sb;
	if (stat(cmd, &sb) == 0)
	{
		printf("cmd found : %s\n", cmd);
		return 0;
	}
	printf("cmd not found\n");
	return EXIT_SUCCESS;
}
