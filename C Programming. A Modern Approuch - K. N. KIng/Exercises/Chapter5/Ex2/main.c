#include <stdio.h>
#include <stdlib.h>

int main()
{
    /// a)
    int i=10, j=5;
    printf("%d\n", !i<j);

    /// b)
    i=2;
    j=1;
    printf("%d\n", !!i+!j);

    /// c)
    int k = -5;
    i=5;
    j=0;
    printf("%d\n", i&&j||k);

    /// d)
    i=1;j=2;k=3;
    printf("%d", i<j||k);
    return 0;
}
