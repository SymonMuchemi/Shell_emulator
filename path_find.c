#include "main.h"
/**
* find_the_path - an pointer that trys to access the given path using x_OK
* @command: the given input by user
* @path: the array of pointers to the desired executable file
* Return: NULL value on success
*/
char *find_the_path(char *command, char *path[])
{
	char exec_path[BUFSIZE];
	int i;

	if (access(command, X_OK) == 0)
		return (command);

	for (i = 0; path[i] != NULL; i++)
	{
		snprintf(exec_path, sizeof(exec_path), "%s/%s", path[i], command);
		if (access(exec_path, X_OK) == 0)
			return (strdup(exec_path));

	}
	return (NULL);
}
/**
 * parse_path - parse the PATH environment variable and store the
 * individual paths in the path array.
 * @path: array of strings
 * @max_paths: maximum paths
 * Return: int
 */
int parse_path(char *path[], int max_paths)
{
	char *path_var = getenv("PATH");
	int i = 0;

	if (path_var == NULL)
		return (-1);

	path[i++] = strtok(path_var, ":");
	while (i < max_paths && (path[i] = strtok(NULL, ":")) != NULL)
		i++;

	return (i);
}
/**
 * execute_command - process an arg and executes it
 * @args:  command line arguments
 * @path: executable file's path
 * Return: nothing
 */
void execute_command(char **args, char **path)
{
	pid_t pid = fork();
	char *executable_path = find_the_path(args[0], path);

	if (executable_path != NULL)
	{
		if (pid < 0)
		{
			perror("Process execution failed");
			return;
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
