/**
 * clear_info - initializes info_t struct
 * @info: struct address
 */
void clear_info(info_t *info)
{
info->argc = 0;
info->argv = NULL;
info->env = NULL;
}
/**
 * free_info - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void free_info(info_t *info, int all)
{
ffree(info->argv);
info->argv = NULL;
info->path = NULL;
}
if (all)
{
if (all)
{
free(info->path);
}
if (info->argv)
{
for (int i = 0; info->argv[i]; i++)
{
free(info->argv[i]);
}
free(info->argv);
}

info->path = NULL;
info->argv = NULL;
}
/**
* set_info - initializes info_t struct
* @info: struct address
* @av: argument vector
*/
void set_info(info_t *info, char **av)
{
int i = 0;

info->fname = av[0];
if (info->arg)
{
info->argv = strtow(info->arg, " \t");
if (!info->argv)
{
info->argv = malloc(sizeof(char *) * 2);
if (info->argv)
{
info->argv[0] = _strdup(info->arg);
info->argv[1] = NULL;
}
}
for (i = 0; info->argv && info->argv[i]; i++)
;
info->argc = i;
replace_alias(info);
replace_vars(info);
}
}
