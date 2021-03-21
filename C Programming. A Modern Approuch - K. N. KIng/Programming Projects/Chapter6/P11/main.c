#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    float e=1.00f, factorial=1;
    printf("n = ");
    scanf("%d", &n);

    for(i=1; i<=n;i++)
    {
        factorial = factorial*i;
        e = e + 1/factorial;
    }

    printf("e = %f", e);
    return 0;
}
