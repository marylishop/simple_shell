#include "shell.h"

/**
 *_erratoi - A string to be converted to an integer
 *@s: the string
 *
 *Return: 0 if no numbers in string,
 *converted number otherwise
 *-1 on error
 */
int _erratoi(char *s)
{
int a = 0;
unsigned long int r = 0;

if (*s == '+')
s++;  /* TODO: why does this make main return 255? */
for (a = 0;  s[a] != '\0'; a++)
	{
if (s[a] >= '0' && s[a] <= '9')
{
r *= 10;
r += (s[a] - '0');
if (r > INT_MAX)
return (-1);
}
else
return (-1);
}
return (r);
}

/**
 *print_error - An error message to be print
 *@info: The parameter
 *@estr: The string (specified erro)
 *Return: 0 if no numbers in string,
 *otherwise converted number
 *-1 on error
 */
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}

/**
 * print_d - prints a decimal 'integer' number 'base 10' in a function
 * @input: the input
 * @fd: the file descript
 *
 *Return: To the number of characters printed
 */
int print_d(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int a, cnt = 0;
unsigned int _abs_, crrnt;

if (fd == STDERR_FILENO)
__putchar = _eputchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
cnt++;
}
else
_abs_ = input;
crrnt = _abs_;
for (a = 1000000000; a > 1; a /= 10)
{
if (_abs_ / a)
{
__putchar('0' + crrnt / a);
cnt++;
}
crrnt %= a;
}
__putchar('0' + crrnt);
cnt++;

return (cnt);
}

/**
 *convert_number - A function and clone to be converted
 *@num: The number
 *@base: The base
 *@flags: The flags argmnt
 *
 *Return: To the string
 */
char *convert_number(long int num, int base, int flags)
{
static char *ary;
static char buf[50];
char sgn = 0;
char *p;
unsigned long x = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
x = -num;
sgn = '-';

}
ary = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
p = &buf[49];
*p = '\0';

do	{
*--p = ary[x % base];
x /= base;
} while (x != 0);

if (sgn)
*--p = sgn;
return (p);
}

/**
 *remove_comments - Replaces first instance of '#' with '\0' in a function
 *@buf: The  address of the string
 *
 *Return: Always 0 (Success)
 */
void remove_comments(char *buf)
{
int a;

for (a = 0; buf[a] != '\0'; a++)
if (buf[a] == '#' && (!a || buf[a - 1] == ' '))
{
buf[a] = '\0';
break;
}
}
