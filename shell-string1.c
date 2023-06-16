#include "shell.h"

/**
 *_strcpy - A string to be copied
 *@dest: the destination
 *@src: the source
 *
 *Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
int a = 0;

if (dest == src || src == 0)
return (dest);
while (src[a])
{
dest[a] = src[a];
a++;
}
dest[a] = 0;
return (dest);
}

/**
 *_strdup - A string do be duplicated
 *@str: the string
 *
 *Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
int l = 0;
char *rt;

if (str == NULL)
return (NULL);
while (*str++)
l++;
rt = malloc(sizeof(char) * (l + 1));
if (!rt)
return (NULL);
for (l++; l--;)
rt[l] = *--str;
return (rt);
}

/**
 *_puts - An  input string printed
 *@str: the string
 *
 *Return: Nothing
 */
void _puts(char *str)
{
int a = 0;

if (!str)
return;
while (str[a] != '\0')
{
_putchar(str[a]);
a++;
}
}

/**
 *_putchar - The character to stdout is writted
 *@c: The character
 *
 *Return: 1 in Success, -1 on error, and errno is set appropriately.
 */
int _putchar(char c)
{
static int a;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
{
write(1, buf, a);
a = 0;
}
if (c != BUF_FLUSH)
buf[a++] = c;
return (1);
}
