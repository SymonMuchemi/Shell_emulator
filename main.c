#include "main.h"
/**
 * main - the shell playground
 * Return: 0 on success or something else
 */
int main(void)
{
	ssize_t nread;
	size_t len = 0;
	char *args[MAX_ARGS], *path[MAX_ARGS], *line;
	int i = parse_path(path, MAX_ARGS);

	if (i == -1)
		perror(".hsh");

	while (1)
	{
		_print_str("");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;
		remove_newline(line);
		tokenize_args(args, line);
		if (args[0] == NULL)
			continue;

		execute_command(args, path);
	}
	free(line);
	return (0);
}
