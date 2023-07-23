#include "main.h"

/**
 * main - the shell playground
 * Return: 0 on success or something else
 */
/*Look at argv[5]*/
int main(int argc, char const **argv, char **envp)
{
	char *line = NULL;
    int result;
	ssize_t nread;
	size_t len = 0;
	pid_t pid;
    char *args[11];

	(void)argc;
    (void)argv;

	while (1)
	{
		_print_str("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;
        
        tokenize_args(args, line);
        /**args = "/bin/ls", "-l";*/
        printf("\nArgument passed: %s.\n", args[0]);
        pid = fork();

        if (pid == -1)
        {
            perror("Process execution failed");
            continue;
        }
        else if (pid == 0)
        {
            result = execve(args[0], args, envp);
            if (result == -1)
            {
                perror("./shell: No such file or directory");
                _exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(NULL);
        }
        /*result = execve(line, args, envp);
        if (result == -1)
            perror("./shell: No such file or directory");
        */
		_print_str(line);
	}
	free(line);
	return (0);
}
