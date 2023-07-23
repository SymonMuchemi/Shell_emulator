#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFSIZE 1024

char *create_buf(char *buf);
void _print_str(char *c);
int _putchar(char c);
void tokenize_args(char **args_array, char *str);

#endif