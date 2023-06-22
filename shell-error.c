#include "shell.h"

/**
 *_eputs - An input string to be print
 *@str: The string
 *
 *Return: Nothing
 */
void _eputs(char *str)
{
int a = 0;

if (!str)
return;
while (str[a] != '\0')
{
_eputchar(str[a]);
a++;
}
}

/**
 *_eputchar - The character c to be writed to stderr
 *@c: The character
 *
 *Return: 1 (Success). On error, -1 is returned,
 *errno is set appropriately
 */
int _eputchar(char c)
{
static int a;
static char bf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
{
write(2, bf, a);
a = 0;
}
if (c != BUF_FLUSH)
bf[a++] = c;
return (1);
}

/**
 * _putfd - The charcater c to be writed to given fd
 *@c: The character
 *@fd: The file descript
 *
 *Return: 1 (SUccess).On error, -1 is returned,
 * errno is set appropriately.
 */
int _putfd(char c, int fd)
{
static int a;
static char bf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
{
write(fd, bf, a);
a = 0;
}
if (c != BUF_FLUSH)
bf[a++] = c;
return (1);
}

/**
 *_putsfd - An input string to be print
 *@str: The string
 *@fd: The file descript
 *
 *Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
int a = 0;

if (!str)
return (0);
while (*str)
{
a += _putfd(*str++, fd);
}
return (a);
}
