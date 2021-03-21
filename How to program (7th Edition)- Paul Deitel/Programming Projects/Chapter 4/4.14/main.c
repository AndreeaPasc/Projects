/// Factorials

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int factorial = 1, n = 5, i;

    for(i = 1; i <= 5; i++){
        factorial = factorial * i;
        printf("%d! = %d\t", i, factorial);
    }
    return 0;
}
