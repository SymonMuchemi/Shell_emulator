#include "main.h"
/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
if (c == '\n')
{
char newline = '\n';
return (write(1, &newline, 1));
}
else
{
return (write(1, &c, 1));
}
}
/**
* create_buf - Create a buffer object
* @filename: name of file
* @buf: parameter
* Return: pointer too created buffer or code 99
*/
char *create_buf(char *buf)
{
buf = malloc(sizeof(char) * BUFSIZE);
if (buf == NULL)
{
perror("Error creating buffer!");
exit(EXIT_FAILURE);
}

return (buf);
}
/**
* _print_str - function that calls the _putchar
* _putchar - writes the character c to stdout
* @c: The character to print
*@string: characters passed
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
void _print_str(char *string)
{
int i = 0;

while (string[i] != '\0')
{
_putchar(string[i]);
i++;
}
}
/**
* tokenize_args - creates an array of command-line arguments
* by splitting it using space as the delimiter
* @args_array: array of arguments
* @str: string to be tokenized
* @i: indexing variable
* Return: nothing
*/
void tokenize_args(char **args_array, char *str)
{
char *token, *delim;
int i = 0;

delim = " \t\n";
token = strtok(str, delim);

while (token && i < MAX_ARGS - 1)
{
args_array[i++] = token;
token = strtok(NULL, delim);
}
args_array[i] = NULL;
}

/**
* find_the_path - an pointer that trys to access the given path using x_OK
* @command: the given input by user
* @path: the array of pointers to the desired executable file
* Return: give NULL value on success
*/

char *find_the_path(char *command, char *path[])
{
char executable_path[BUFSIZE];
int i;

if (access(command, X_OK) == 0)
{
return (command);
}

for (i = 0; path[i] != NULL; i++)
{
snprintf(executable_path, sizeof(executable_path), "%s/%s", path[i], command);
if (access(executable_path, X_OK) == 0)
{
return (strdup(executable_path));
}
}
return (NULL);
}

