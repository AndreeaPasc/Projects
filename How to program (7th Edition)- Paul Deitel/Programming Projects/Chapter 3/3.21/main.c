/// Predecrementing vs. postdecrementing

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k = 8;
    printf("k = %d\n", k);
    printf("k-- = %d\n", k--);
    printf("k = %d\n\n", k);

    k = 8;
    printf("k = %d\n", k);
    printf("--k = %d\n", --k);
    printf("k = %d", k);
    return 0;
}
