#include "shell.h"
/**
 **_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
s[i] = b;
return (s);
}
/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
char **a = pp;

if (!pp)
return;
while (*pp)
free(*pp++);
free(a);
}
/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @old_size: The size in bytes of the allocated space for ptr.
 * @new_size: The size in bytes for the new memory block.
 *
 * Return: If new_size == old_size - ptr.
 *         If new_size == 0 and ptr is not NULL - NULL.
 *         Otherwise - a pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *mem;
char *ptr_copy, *filler;
unsigned int index;
if (new_size == old_size)
return (ptr);
if (ptr == NULL)
{
mem = malloc(new_size);
if (mem == NULL)
return (NULL);
return (mem);
}
if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}
ptr_copy = ptr;
mem = malloc(sizeof(*ptr_copy) * new_size);
if (mem == NULL)
{
free(ptr);
return (NULL);
}
filler = mem;
for (index = 0; index < old_size && index < new_size; index++)
filler[index] = *ptr_copy++;

free(ptr);
return (mem);
}
