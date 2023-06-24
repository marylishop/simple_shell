#include "shell.h"


/**
 * replace_string - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
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
 * replace_vars - replaces vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
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
char *pp;
for (i = 0; info->argv[i]; i++)
{
node = node_starts_with(info->alias, info->argv[i], '=');
if (node)
{
pp = strchr(node->str, '=');
if (pp)
{
replace_string(&(info->argv[i]), _strdup(pp + 1));
continue;
}
}
}
return (0);
}
