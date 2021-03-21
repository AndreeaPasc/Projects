#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k;

    i=1;
    printf("%d\n", i++ - 1);
    printf("%d", i);

    i=10; j=5;
    printf("\n\n%d\n", i++ - ++j);
    printf("%d %d\n\n", i, j);

    i=7;j=8;
    printf("%d\n\n", i++ - --j);
    printf("%d %d\n\n", i, j);

    i=3;j=4;k=5;
    printf("%d ", i++ - j++ + --k);
    printf("%d %d %d", i, j, k);
    return 0;
}
