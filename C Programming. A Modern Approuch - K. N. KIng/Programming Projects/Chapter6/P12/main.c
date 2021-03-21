#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    float e=1.00f, factorial=1, epsilon;

    printf("Epsilon = ");
    scanf("%f", &epsilon);
    while(1/factorial>=epsilon)
    {
        factorial = factorial*i;
        e = e + 1/factorial;
        i++;
    }

    printf("e = %f", e);
    return 0;
}
