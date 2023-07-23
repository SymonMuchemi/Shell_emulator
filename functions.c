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
        return write(1, &newline, 1);
    }
    else
    {
        return write(1, &c, 1);
    }
}
/**
 * create_buf - Create a buffer object
 * @filename: name of file
 * Return: pointer too created buffer or code 99
 */
char *create_buf(char *buf)
{
    buf = malloc(sizeof(char) * 1024);
    if (buf == NULL)
    {
        perror("Error creating buffer!");
		exit(99);
    }

    return (buf);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
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

    delim = " ";
    token = strtok(str, delim);

    while (token)
    {
        args_array[i++] = token;
        token = strtok(NULL, delim);
    }
    args_array[i] = NULL;
}
