#include "shell.h"

/**
 *hsh - The shell loop of main
 *@info: The parameter struct
 *@av: The argmnt vector
 *
 *Return: 0  (Success)
 *1 on error, or error code
 */
int hsh(info_t *info, char **av)
{
ssize_t R = 0;
int bltn_rt = 0;

while (R != -1 && bltn_rt != -2)
{
clear_info(info);
if (interactive(info))
_puts("$ ");
_eputchar(BUF_FLUSH);
R = get_input(info);
if (R != -1)
{
set_info(info, av);
bltn_rt = find_builtin(info);
if (bltn_rt == -1)
find_cmd(info);
}
else if (interactive(info))
_putchar('\n');
free_info(info, 0);
}
write_history(info);
free_info(info, 1);
if (!interactive(info) && info->status)
exit(info->status);
if (bltn_rt == -2)
{
if (info->err_num == -1)
exit(info->status);
exit(info->err_num);
}
return (bltn_rt);
}

/**
 *find_builtin - A builtin command to find
 *@info: The parameter struct
 *
 *Return: -1 if builtin not found,0 if builtin executed successfully,
 *1 if builtin found but not successful,
 *-2 if builtin signals exit()
 */
int find_builtin(info_t *info)
{
int a, built_in_ret = -1;
builtin_table builtintbl[] = {
{"exit", _myexit},
{"env", _myenv},
{"help", _myhelp},
{"history", _myhistory},
{"setenv", _mysetenv},
{"unsetenv", _myunsetenv},
{"cd", _mycd},
{"alias", _myalias},
{NULL, NULL}
};

for (a = 0; builtintbl[a].type; a++)
if (_strcmp(info->argv[0], builtintbl[a].type) == 0)
{
info->line_count++;
built_in_ret = builtintbl[a].func(info);
break;
}
return (built_in_ret);
}

/**
 *find_cmd - A commands finded in PATH
 *@info: The parameter struct
 *
 *Return: void
 */
void find_cmd(info_t *info)
{
char *path = NULL;
int a, m;

info->path = info->argv[0];
if (info->linecount_flag == 1)
{
info->line_count++;
info->linecount_flag = 0;
}
for (a = 0, m = 0; info->arg[a]; a++)
if (!is_delim(info->arg[a], " \t\n"))
m++;
if (!m)
return;

path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
if (path)
{
info->path = path;
fork_cmd(info);
}
else
{
if ((interactive(info) || _getenv(info, "PATH=")
|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
fork_cmd(info);
else if (*(info->arg) != '\n')
{
info->status = 127;
print_error(info, "not found\n");
}
}
}

/**
 *fork_cmd - forks a an exec thread to run cmd
 *@info: the parameter & return info struct
 *
 *Return: void
 */
void fork_cmd(info_t *info)
{
pid_t child_pid;

child_pid = fork();
if (child_pid == -1)
{
/* TODO: PUT ERROR FUNCTION */
perror("Error:");
return;
}
if (child_pid == 0)
{
if (execve(info->path, info->argv, get_environ(info)) == -1)
{
free_info(info, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
/* TODO: PUT ERROR FUNCTION */
}
else
{
wait(&(info->status));
if (WIFEXITED(info->status))
{
info->status = WEXITSTATUS(info->status);
if (info->status == 126)
print_error(info, "Permission denied\n");
}
}
}
