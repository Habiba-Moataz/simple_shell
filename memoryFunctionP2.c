#include"shell.h"

/**
 * realloc - reallocates a block of memory
 * @ptr: a pointer to previous mallocated block
 * @oldSize: byte size of previous block
 * @newSize: byte size of new block
 * Return: pointer to da ol block namen
 */
void *_realloc(void *ptr, unsigned int oldSize, unsigned int newSize).
{
        char *z;

        if(!ptr)
                return (malloc(newSize));
        if(!newSize)
                return(free(ptr),NULL);
        if(newSize == oldSize)
                return(ptr);

        z = malloc(newSize);
        if(!z)
                return(NULL);
        oldSize = oldSize < newSize ? oldSize : newSize;
        while (oldSize--)
                z[oldSize] = ((char *)ptr)[oldSize];
        free(ptr);
        return(z);
}

/**
 * bfree - frees a pointer and Nulls the address
 * @ptr: address of the pointer to free
 * Return: 1 if freed , 0 otherwise
 */
int bfree( void **ptr)
{
	if(ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return(1);
	}
	return(0);
}
