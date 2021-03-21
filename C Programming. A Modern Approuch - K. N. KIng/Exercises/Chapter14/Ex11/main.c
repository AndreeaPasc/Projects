#include <stdio.h>

#define ERROR(s, ...) fprintf(stderr, s, __VA_ARGS__)

int main(void)
{
    int index = 10;
    putchar('\n');
    ERROR("Range error: index = %d\n", index);
    putchar('\n');
    return 0;
}