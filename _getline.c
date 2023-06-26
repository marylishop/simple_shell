#include "shell.h"

/**
 *input_buf - The buffers chained commands
 *@info: The parameter
 *@buf: The buffer adress
 *@len: The len adress
 *
 *Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
ssize_t R = 0;
size_t l_p = 0;

if (!*len) /* if nothing left in the buffer, fill it */
{
/*bfree((void **)info->cmd_buf);*/
free(*buf);
*buf = NULL;
signal(SIGINT, sigintHandler);
#if USE_GETLINE
R = getline(buf, &l_p, stdin);
#else
R = _getline(info, buf, &l_p);
#endif
if (R > 0)
{
if ((*buf)[R - 1] == '\n')
{
(*buf)[R - 1] = '\0'; /* remove trailing newline */
R--;
}
info->linecount_flag = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->histcount++);
/* if (_strchr(*buf, ';')) is this a command chain? */
{
*len = R;
info->cmd_buf = buf;
}
}
}
return (R);
}

/**
 *get_input - A line minus the newline is geted
 *@info: The parameter
 *
 *Return: bytes read
 */
ssize_t get_input(info_t *info)
{
static char *buf; /* the ';' command chain buffer */
static size_t a, b, l;
ssize_t R = 0;
char **buf_p = &(info->arg), *p;

_putchar(BUF_FLUSH);
R = input_buf(info, &buf, &l);
if (R == -1) /* EOF */
return (-1);
if (l)/* we have commands left in the chain buffer */
{
b = a; /* init new iterator to current buf position */
p = buf + a; /* get pointer for return */

check_chain(info, buf, &b, a, l);
while (b < l) /* iterate to semicolon or end */
{
if (is_chain(info, buf, &b))
break;
b++;
}

a = b + 1; /* increment past nulled ';'' */
if (a >= l) /* reached end of buffer? */
{
a = l = 0; /* reset position and length */
info->cmd_buf_type = CMD_NORM;
}

*buf_p = p; /* pass back pointer to current command position */
return (_strlen(p)); /* return length of current command */
}

*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
return (R); /* return length of buffer from _getline() */
}

/**
 *read_buf - A buffer to read
 *@info:The parameter
 *@buf: The buffer
 *@i: The size
 *
 *Return: R
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
ssize_t R = 0;

if (*i)
return (0);
R = read(info->readfd, buf, READ_BUF_SIZE);
if (R >= 0)
*i = R;
return (R);
}

/**
 *_getline -  The next line of input geted from STDIN
 *@info: The parametr struct
 *@ptr: Thenpointers adress
 *@length: The preallocated's size
 *
 *Return: S
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
static char buf[READ_BUF_SIZE];
static size_t a, l;
size_t b;
ssize_t R = 0, S = 0;
char *p = NULL, *new_p = NULL, *c;

p = *ptr;
if (p && length)
S = *length;
if (a == l)
a = l = 0;

R = read_buf(info, buf, &l);
if (R == -1 || (R == 0 && l == 0))
return (-1);

c = _strchr(buf + a, '\n');
b = c ? 1 + (unsigned int)(c - buf) : l;
new_p = _realloc(p, S, S ? S + b : b + 1);
if (!new_p) /* MALLOC FAILURE! */
return (p ? free(p), -1 : -1);

if (S)
_strncat(new_p, buf + a, b - a);
else
_strncpy(new_p, buf + a, b - a + 1);

S += b - a;
a = b;
p = new_p;

if (length)
*length = S;
*ptr = p;
return (S);
}

/**
 *sigintHandler - The  Controle C to block
 *@sig_num: the signal
 *
 *Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUF_FLUSH);
}
