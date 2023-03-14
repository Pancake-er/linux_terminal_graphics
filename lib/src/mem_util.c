#include <stdio.h>
#include <stdlib.h>

void *malloc_or_die(size_t size)
{
    void *alloc_mem = malloc(size);

    if(alloc_mem == NULL)
    {
        perror("Failed to allocate memory");
        free(alloc_mem);
        exit(EXIT_FAILURE);
    }
    return alloc_mem;
}