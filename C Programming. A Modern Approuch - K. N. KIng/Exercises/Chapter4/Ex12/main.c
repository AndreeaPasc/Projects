#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k;

    i=5;
    j = ++i * 3 - 2;
    printf("%d %d\n\n", i, j);

    i=10;
    j=3 - 2 * i++;
    printf("%d %d\n\n", i, j);

    i=7;
    j=3 * i-- + 2;
    printf("%d %d\n\n", i, j);

    i=7;
    j = 3 + --i * 2;
    printf("%d %d", i, j);
    return 0;
}
