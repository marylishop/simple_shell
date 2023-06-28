#include "shell.h"

/**
 *read_line - The input string to be read
 *@i_eof: The return value
 *
 *Return: input string
 */
char *read_line(int *i_eof)
{
char *input = NULL;
size_t bufsize = 0;

*i_eof = getline(&input, &bufsize, stdin);

return (input);
}
