#include "shell.h"

/**
 *_strcat - concatenate two strings
 *@dest: char pointer the dest of the copied str
 *@src: const char pointer the source of str
 *
 *Return: the dest
 */
char *_strcat(char *dest, const char *src)
{
int i;
int j;

for (i = 0; dest[i] != '\0'; i++)
;

for (j = 0; src[j] != '\0'; j++)
{
dest[i] = src[j];
i++;
}

dest[i] = '\0';
return (dest);
}
/**
 **_strcpy - Thhe string pointed to by src to be copie
 *@dest: The char pointer
 *@src: The char source
 *
 *Return: the dest.
 */
char *_strcpy(char *dest, char *src)
{

size_t a;

for (a = 0; src[a] != '\0'; a++)
{
dest[a] = src[a];
}
dest[a] = '\0';

return (dest);
}
/**
 * _strcmp - Function that compares two strings.
 * @s1: The string One
 * @s2: The string Two
 *
 *Return: Always 0 (Success).
 */
int _strcmp(char *s1, char *s2)
{
int i;

for (i = 0; s1[i] == s2[i] && s1[i]; i++)
;

if (s1[i] > s2[i])
return (1);
if (s1[i] < s2[i])
return (-1);
return (0);
}
/**
 *_strchr - A character in a string to be located
 *@s: The string.
 *@c: The character.
 *
 *Return: the pointer to the first occurrence of the character c.
 */
char *_strchr(char *s, char c)
{
unsigned int i = 0;

for (; *(s + i) != '\0'; i++)
if (*(s + i) == c)
return (s + i);
if (*(s + i) == c)
return (s + i);
return ('\0');
}
/**
 *_strspn - The length of a prefix substring to be get
 *@s: The segment.
 *@accept: The accepted bytes.
 *
 *Return: The number of accepted bytes.
 */
int _strspn(char *s, char *accept)
{
int i, j, bool;

for (i = 0; *(s + i) != '\0'; i++)
{
bool = 1;
for (j = 0; *(accept + j) != '\0'; j++)
{
if (*(s + i) == *(accept + j))
{
bool = 0;
break;
}
}
if (bool == 1)
break;
}
return (i);
}
