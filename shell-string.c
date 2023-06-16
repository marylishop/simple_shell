#include "shell.h"

/**
 *_strlen - The lengenth of string returned
 *@s: the string
 *
 *Return: integer length of string
 */
int _strlen(char *s)
{
int a = 0;

if (!s)
return (0);

while (*s++)
a++;
return (a);
}

/**
 *_strcmp - The comparaison of two string
 *@s1: String One
 *@s2: String Two
 *
 *Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
 *starts_with - The needle starts with haystack or not.
 *@haystack: The string
 *@needle: The substring
 *
 *Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
 *_strcat - Two string concatenated
 *@dest: Destination buffer
 *@src: Source buffer
 *
 *Return: Return to destination buffer
 */
char *_strcat(char *dest, char *src)
{
char *rt = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (rt);
}
