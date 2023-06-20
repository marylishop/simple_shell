#include "shell.h"

/**
 *_myhistory - To display the history list with line numbers, starting at 0,
 *where each command is listed on a separate line
 *@info: The struct containing the potential argmnts
 *
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
 *unset_alias - The alias seted to string
 *@info: The parameter struct
 *@str: The string
 *
 *Return: Always 0 on success,
 *1 on error
 */
int unset_alias(info_t *info, char *str)
{
char *b, s;
int rt;

b = _strchr(str, '=');
if (!b)
return (1);
s = *b;
*b = 0;
rt = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*b = s;
return (rt);
}

/**
 *set_alias - An alias seted to string
 *@info: The parameter struct
 *@str: The string
 *
 *Return: Always 0 on success,
 *1 on error
 */
int set_alias(info_t *info, char *str)
{
char *c;

c = _strchr(str, '=');
if (!c)
return (1);
if (!*++c)
return (unset_alias(info, str));

unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 *print_alias - An alias  string to be print
 *@node: The node of alias
 *
 *Return: Always 0 on success,
 *1 on error
 */
int print_alias(list_t *node)
{
char *c = NULL, *x = NULL;

if (node)
{
c = _strchr(node->str, '=');
for (x = node->str; x <= c; x++)
_putchar(*x);
_putchar('\'');
_puts(c + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
 *_myalias -  The alias builtin to be mimic
 *@info: The struct containing the potential argmnt
 *
 *Return: Always 0 (Success)
 */
int _myalias(info_t *info)
{
int a = 0;
char *c = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (a = 1; info->argv[a]; a++)
{
c = _strchr(info->argv[a], '=');
if (c)
set_alias(info, info->argv[a]);
else
print_alias(node_starts_with(info->alias, info->argv[a], '='));
}
return (0);
}
