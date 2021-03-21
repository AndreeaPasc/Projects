#include <stdio.h>

int main() {
    unsigned int i, j, k;

    /// a)
    i = 8; j= 9;
    printf("%d\n", i>>1+j>>1);

    /// b)
    i=1;
    printf("%d\n", i&~i);

    /// c)
    i=2; j=1; k=0;
    printf("%d\n", ~i&j^k);

    ///d)
    i=7; j=8; k=9;
    printf("%d", i^j&k);
    return 0;
}