#include "shell.h"
/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str, char *d)
{
int i, j, k, m, numwords = 0;
char **s;
if (str == NULL || d == NULL || str[0] == '\0' || d[0] == '\0')
return (NULL);
/* Count the number of words */
for (i = 0; str[i] != '\0'; i++)
{
if (str[i] != d[0] && (str[i + 1] == '\0' || strchr(d, str[i + 1]) != NULL))
numwords++;
}
if (numwords == 0)
return (NULL);
s = malloc((numwords + 1) * sizeof(char *));
if (s == NULL)
return (NULL);
i = 0;
j = 0;
/* Extract the words and store them in the array */
while (str[i] != '\0')
{
while (str[i] == d[0])
i++;
k = 0;
while (str[i + k] != d[0] && str[i + k] != '\0')
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (s[j] == NULL)
{
for (m = 0; m < j; m++)
free(s[m]);
free(s);
return (NULL);
}
strncpy(s[j], &str[i], k);
s[j][k] = '\0';
i += k;
j++;
}
s[j] = (NULL);
return (s);
}
/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
int i, j, k, m, numwords = 0;
char **s;
if (str == NULL || str[0] == '\0')
return (NULL);
for (i = 0; str[i] != '\0'; i++)
if ((str[i] != d && str[i + 1] == d) ||
(str[i] != d && !str[i + 1]) || str[i + 1] == d)
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((numwords + 1) * sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
while (str[i] == d)
i++;
k = 0;
while (str[i + k] != d && str[i + k] != '\0')
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{
for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[j][m] = str[i + m];
s[j][m] = '\0';
i += k;
}
s[j] = NULL;
return (s);
}
