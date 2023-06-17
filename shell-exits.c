#include "shell.h"

/**
 **_strncpy - A string to be copied
 *@dest: the destination
 *@src: the source
 *@n: The characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
int a, b;
char *s = dest;

a = 0;
while (src[a] != '\0' && a < n - 1)
{
dest[a] = src[a];
a++;
}
if (a < n)
{
b = a;
while (b < n)
{
dest[b] = '\0';
b++;
}
}
return (s);
}

/**
 **_strncat - Two strings to be concatenated
 *@dest: the string one
 *@src: the string two
 *@n: the bytes must used
 *Return: To the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
int a, b;
char *s = dest;

a = 0;
b = 0;
while (dest[a] != '\0')
a++;
while (src[b] != '\0' && b < n)
{
dest[a] = src[b];
a++;
b++;
}
if (b < n)
dest[a] = '\0';
return (s);
}

/**
 **_strchr - The character located to a string
 *@s: the string
 *@c: the character
 *Return: to s , The  pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');

return (NULL);
}
