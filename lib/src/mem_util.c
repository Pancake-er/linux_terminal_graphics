#include <stdio.h>
#include <stdlib.h>

void *malloc_or_die(size_t size)
{
    void *alloc_mem = malloc(size);

    if(alloc_mem == NULL)
    {
        free(alloc_mem);
        fprintf(stderr, "\e[0;30mFailed to allocate memory\n");
        fflush(stderr);
        exit(EXIT_FAILURE);
    }
    return alloc_mem;
}