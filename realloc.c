#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @m: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (m) a pointer to the memory area m
 */

char *_memset(char *m, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		m[i] = b;
	return (m);
}

/**
 * ffree - frees a string of strings
 * @vv: string of strings
 */

void ffree(char **vv)
{
	char **a = vv;

	if (!vv)
		return;
	while (*vv)
		free(*vv++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 * Return: pointer to da ol'block nameen.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *v;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	v = malloc(new_size);
	if (!v)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		v[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (v);
}
