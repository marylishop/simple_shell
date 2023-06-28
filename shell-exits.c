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
int i, j;
char *s = dest;

i = 0;
while (src[i] != '\0' && i < n - 1)
{
dest[i] = src[i];
i++;
}
if (i < n)
{
j = i;
while (j < n)
{
dest[j] = '\0';
j++;
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
int i, j;
char *s = dest;

i = 0;
j = 0;
while (dest[i] != '\0')
i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string
 *@c: the character
 *Return: to (s) , The  pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');

return (NULL);
}
