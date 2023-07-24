#include "main.h"

/**
 * main - the shell playground
 * Return: 0 on success or something else
 */
/*Look at argv[5]*/
int main(void)
{
	char *line = NULL;
    /**int result;*/
	ssize_t nread;
	size_t len = 0;
	pid_t pid;
    char *args[MAX_ARGS];
    /**char *arguments[] ={"/bin/ls", NULL};


    argv = arguments;
    */

	while (1)
	{
		_print_str("#cisfun$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;
        
        tokenize_args(args, line);
        /**args = "/bin/ls", "-l";
        printf("\nArgument passed: %s.\n", args[0]);*/
	if (args[0] == NULL)
		continue;

        pid = fork();

        if (pid < 0)
        {
            perror("Process execution failed");
            continue;
        }
        else if (pid == 0)
        {
            execve(args[0], args, NULL);
            perror("./shell: No such file or directory");
            _exit(EXIT_FAILURE);
        }
        else
        {
            wait(NULL);
        }
        /**result = execve(line, args, envp);
        if (result == -1)
            perror("./shell: No such file or directory");
        
		_print_str(line);
	}
	*/
}
	free(line);
	return (0);

}
