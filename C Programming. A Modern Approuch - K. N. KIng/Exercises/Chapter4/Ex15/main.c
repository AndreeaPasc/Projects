#include <stdio.h>
#include <stdlib.h>

int main()
{
    int  i = 1, j = 2;

    /// a)
    i += j;
    printf("%d %d\n\n", i, j);

    /// b)
    i = 1; j = 2;
    i--;
    printf("%d\n\n", i);

    /// c)
    i=1;j=2;
    int k = i*j/i;
    printf("%d\n\n", k);

    /// d)
    i=1; j=2;
    k = i% ++j;
    printf("%d", k);

    return 0;
}
