#include "shell.h"

/**
 *get_history_file - The history file to be geted
 *@info: The struct
 *
 *Return: The string containg file allocated
 */

char *get_history_file(info_t *info)
{
	char *bf, *d;

d = _getenv(info, "HOME=");
if (!d)
return (NULL);
bf = malloc(sizeof(char) * (_strlen(d) + _strlen(HIST_FILE) + 2));
if (!bf)
return (NULL);
bf[0] = 0;
_strcpy(bf, d);
_strcat(bf, "/");
_strcat(bf, HIST_FILE);
return (bf);
}

/**
 *write_history -  A file to be created
 *@info: The struct
 *
 *Return: 1  (Success)
 * else -1
 */
int write_history(info_t *info)
{
ssize_t ft;
char *fname = get_history_file(info);
list_t *node = NULL;

if (!fname)
return (-1);

ft = open(fname, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(fname);
if (ft == -1)
return (-1);
for (node = info->history; node; node = node->next)
{
_putsfd(node->str, ft);
_putfd('\n', ft);
}
_putfd(BUF_FLUSH, ft);
close(ft);
return (1);
}

/**
 *read_history - The history to be readed from file
 *@info: the struct parameter
 *
 *Return: The histcount on success,
 *0 otherwise
 */
int read_history(info_t *info)
{
int a, l = 0, lncnt = 0;
ssize_t fd, rdlen, fsz = 0;
struct stat st;
char *bf = NULL, *fname = get_history_file(info);

if (!fname)
return (0);

fd = open(fname, O_RDONLY);
free(fname);
if (fd == -1)
return (0);
if (!fstat(fd, &st))
fsz = st.st_size;
if (fsz < 2)
return (0);
bf = malloc(sizeof(char) * (fsz + 1));
if (!bf)
return (0);
rdlen = read(fd, bf, fsz);
bf[fsz] = 0;
if (rdlen <= 0)
return (free(bf), 0);
close(fd);
for (a = 0; a < fsz; a++)
if (bf[a] == '\n')
{
bf[a] = 0;
build_history_list(info, bf + l, lncnt++);
l = a + 1;
}
if (l != a)
build_history_list(info, bf + l, lncnt++);
free(bf);
info->histcount = lncnt;
while (info->histcount-- >= HIST_MAX)
delete_node_at_index(&(info->history), 0);
renumber_history(info);
return (info->histcount);
}

/**
 *build_history_list -Entry to be added to a history linked list
 *@info: The struct containing the potential argmnts
 *@buf: The buffer
 *@linecount: The linecount and histcount history's
 *
 *Return: Always 0 (Success)
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
list_t *node = NULL;

if (info->history)
node = info->history;
add_node_end(&node, buf, linecount);

if (!info->history)
info->history = node;
return (0);
}

/**
 *renumber_history - The history linked to be renumbered after change
 *@info: The Struct containing the potential argmnt
 *
 *Return: New histcount.
 */
int renumber_history(info_t *info)
{
list_t *node = info->history;
int a = 0;

while (node)
{
node->num = a++;
node = node->next;
}
return (info->histcount = a);
}
