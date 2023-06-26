#include "shell.h"

/**
 *_myexit - The shell to be exited
 *@info: The Struct containing the potential argmnts
 *
 *Return: exits with a given exit status.(0) if info->argv[0] != "exit"
 */
int _myexit(info_t *info)
{
int ext_check;

if (info->argv[1])  /* If there is an exit arguement */
{
ext_check = _erratoi(info->argv[1]);
if (ext_check == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}

/**
 *_mycd - The current direcotry to be change
 *@info: The Struct containing The potential argmnt
 *
 *Return: Always 0 (Sucess)
 */
int _mycd(info_t *info)
{
char *g, *d, buffer[1024];
int rt;

g = getcwd(buffer, 1024);
if (!g)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
d = _getenv(info, "HOME=");
if (!d)
rt = /* TODO: what should this be? */
chdir((d = _getenv(info, "PWD=")) ? d : "/");
else
rt = chdir(d);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(g);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
rt =
chdir((d = _getenv(info, "OLDPWD=")) ? d : "/");
}
else
rt = chdir(info->argv[1]);
if (rt == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}

/**
 *_myhelp - The current directory to be changed
 *@info: The struct containing the potential argmnt.
 *
 *Return: Always 0 (Success)
 */
int _myhelp(info_t *info)
{
char **argy;

argy = info->argv;
_puts("help call works. Function not yet implemented \n");
if (0)
_puts(*argy); 
return (0);
}
