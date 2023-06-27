#include "shell.h"

/**
 *replace_string - replaces string
 *@old: address of old string
 *@new: new string
 *
 *Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
if (old == NULL || new == NULL)
return (0);

free(*old);
*old = strdup(new);

if (*old == NULL)
return (0);

return (1);
}
/**
 *replace_vars - replaces vars in the tokenized string
 *@info: the parameter struct
 *
 *Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
int i = 0;
list_t *node;

for (i = 0; info->argv[i]; i++)
{
if (info->argv[i][0] != '$' || !info->argv[i][1])
continue;
if (!_strcmp(info->argv[i], "$?"))
{
replace_string(&(info->argv[i]),
_strdup(convert_number(info->status, 10, 0)));
continue;
}
if (!_strcmp(info->argv[i], "$$"))
{
replace_string(&(info->argv[i]),
_strdup(convert_number(getpid(), 10, 0)));
continue;
}
node = node_starts_with(info->env, &info->argv[i][1], '=');
if (node)
{
char *value = strchr(node->str, '=');
if (value)
{
replace_string(&(info->argv[i]), _strdup(value + 1));
continue;
}
}
replace_string(&info->argv[i], _strdup(""));
}
return (0);
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
int i;
list_t *node;
char *p;

for (i = 0; i < 10; i++)
{
node = node_starts_with(info->alias, info->argv[0], '=');
if (!node)
return (0);
free(info->argv[0]);
p = _strchr(node->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
info->argv[0] = p;
}
return (1);
}
/**
 *is_chain - The current char in buffer tested is is a chain delemtier
 *@info: The parameter
 *@buf: The char
 *@p: The address
 *
 *Return: 1 if chain delimeter,
 *Otherwise  0
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
size_t b = *p;

if (buf[b] == '|' && buf[b + 1] == '|')
{
buf[b] = 0;
b++;
info->cmd_buf_type = CMD_OR;
}
else if (buf[b] == '&' && buf[b + 1] == '&')
{
buf[b] = 0;
b++;
info->cmd_buf_type = CMD_AND;
}
else if (buf[b] == ';') /* found end of this command */
{
buf[b] = 0; /* replace semicolon with null */
info->cmd_buf_type = CMD_CHAIN;
}
else
return (0);
*p = b;
return (1);
}

/**
 *check_chain - The checks continue chaining based on last status
 *@info: The parameter struct
 *@buf: The char
 *@p: The address of pstn
 *@i: The starting pstn
 *@len: The length
 *
 *Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
size_t b = *p;

if (info->cmd_buf_type == CMD_AND)
{
if (info->status)
{
buf[i] = 0;
b = len;
}
}
if (info->cmd_buf_type == CMD_OR)
{
if (!info->status)
{
buf[i] = 0;
b = len;
}
}

*p = b;
}
