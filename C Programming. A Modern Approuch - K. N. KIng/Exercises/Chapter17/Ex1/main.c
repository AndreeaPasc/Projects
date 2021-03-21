#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_malloc(size_t size);

int main() {
    int alloc_size = 1;
    ///allocate too much memory
    for(;;)
    {
        char *stuff = my_malloc(alloc_size);
        alloc_size *= 2;
        stuff = NULL;
    }
    return 0;
}

void *my_malloc(size_t size)
{
    void *ret = malloc(size);
    if(ret == NULL)
    {
        printf("Memory allocation error.");
        exit(EXIT_FAILURE);
    }
    return ret;
}