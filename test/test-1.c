#include "../shell.h"
#include <sys/stat.h>



int main(int argc, char **argv)
{
	char *path;
	char **dirs = NULL;
	char *token;
	unsigned int idx = 0;
	struct stat sb;
	char *pwd = getcwd(NULL, 0);

	while (environ[idx])
	{
		if (strncmp(environ[idx], "PATH", 4) == 0)
		{
			path = strdup(environ[idx]);
			printf("%s\n", path);
			break;
		}
		idx++;
	}
	idx = 0;

	token = strtok(&path[5], ":");
	printf("we pass strtok\n");
	while (token)
	{
		dirs = realloc(dirs, (idx + 1) * sizeof(char *));
		dirs[idx] = strdup(token);
		printf("duplicate dirs successfully!\n");
		token = strtok(NULL, ":");
		idx++;
	}
	idx = 0;


	while (dirs[idx])
	{
		chdir(dirs[idx]);
		if (stat(argv[0], &sb) == 0)
		{
			argv[0] = strcat(dirs[idx], argv[0]);
			printf("cmd is : ls\n");
			printf("new cmd is : %s\n", argv[0]);
			break;
		}
		idx++;
	}
	chdir(pwd);
	free2D(dirs);
	free(path);
	free(pwd);

	return EXIT_SUCCESS;
}
