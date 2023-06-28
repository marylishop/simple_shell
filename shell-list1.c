#include "shell.h"

/**
 *list_len - The length of linked list to be determinated
 *@h: The pointer (First node)
 *
 *Return: To the size of list
 */
size_t list_len(const list_t *h)
{
size_t index = 0;

while (h)
{
h = h->next;
index++;
}
return (index);
}

/**
 *list_to_strings - An array of strings of the list->str to be returned
 *@head: The pointer (First node)
 *
 *Return: array of strings
 */
char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t i = list_len(head), j;
char **string;
char *s;

if (!head || !i)
return (NULL);
string = malloc(sizeof(char *) * (i + 1));
if (!string)
return (NULL);
for (i = 0; node; node = node->next, i++)
{
s = malloc(_strlen(node->str) + 1);
if (!s)
{
for (j = 0; j < i; j++)
free(string[j]);
free(string);
return (NULL);
}

s = _strcpy(s, node->str);
string[i] = s;
}
string[i] = NULL;
return (string);
}


/**
 *print_list - All elements of a list_t to be print
 *@h:  The pointer
 *
 *Return: To the size of list
 */
size_t print_list(const list_t *h)
{
size_t a = 0;

while (h)
{
_puts(convert_number(h->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
a++;
}
return (a);
}

/**
 *node_starts_with - The node (string starts with prefix) will be returned
 *@node: The pointer (Head)
 *@prefix: The string
 *@c: The character
 *
 *Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
char *b = NULL;

while (node)
{
b = starts_with(node->str, prefix);
if (b && ((c == -1) || (*b == c)))
return (node);
node = node->next;
}
return (NULL);
}

/**
 *get_node_index - The index of a node to be geted
 *@head: The pointer (head)
 *@node: The pointer (Node)
 *
 *Return: The node's index , or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t a = 0;

while (head)
{
if (head == node)
return (a);
head = head->next;
a++;
}
return (-1);
}
