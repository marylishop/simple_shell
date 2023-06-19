#include "shell.h"

/**
 *bfree - A pointer freeded , the adress NULL
 *@ptr: The adress
 *
 *Return: if free 1.
 *Otherwise 0.
 */
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
