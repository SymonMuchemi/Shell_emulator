#include "main.h"
/**
 * main - the shell playground
 * Return: 0 on success or something else
 */
/*Look at argv[5]*/
int main(void)
{
	ssize_t nread;
	size_t len = 0;
	pid_t pid;
	char *path_var = getenv("PATH");
	char *line, *args[MAX_ARGS], *executable_path, *path[MAX_ARGS];

	initialize_path(path_var, path);
	while (1)
	{
		_print_str("");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;
		tokenize_args(args, line);
		if (args[0] == NULL)
			continue;
		executable_path = find_the_path(args[0], path);
		if (executable_path != NULL)
		{
			pid = fork();
			if (pid < 0)
			{
				perror("Process execution failed");
				continue;
			}
			else if (pid == 0)
			{
				execve(executable_path, args, NULL);
				perror("./shell");
				_exit(EXIT_FAILURE);
			}
			wait(NULL);
		}
	}
	free(line);
	return (0);
}
