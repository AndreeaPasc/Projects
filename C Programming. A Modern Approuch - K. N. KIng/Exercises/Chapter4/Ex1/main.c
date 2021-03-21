#include <stdio.h>
#include <stdlib.h>

int main()
{
    /// a)
    int i=5, j=3;
    printf("%d %d\n", i/j, i%j);

    /// b)
    i=2;
    printf("%d\n", (i+10)%j);

    /// c)
    i=7;j=8;int k=9;
    printf("%d\n", (i+10)%k/j);

    /// d)
    i=1; j=2; k=3;
    printf("%d", (i+5)%(j+2)/k);

    return 0;
}
