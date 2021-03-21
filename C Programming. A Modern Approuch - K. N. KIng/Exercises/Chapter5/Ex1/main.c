#include <stdio.h>
#include <stdlib.h>

int main()
{
    /// a)
    int i=1, j=3, k;
    k = i*j==6;
    printf("%d", k);

    /// b)
    i=5;
    j=10;
    k=1;
    printf("\n%d", k>i<j);

    /// c)
    i=3; j=4; k=5;
    printf("\n%d", i<j == j<k);

    /// d)
    i=3;j=4;k=5;
    printf("\n%d", i%j+i<k);
    return 0;
}
