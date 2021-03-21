#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n, aux, max;
    printf("Enter a series of numbers (terminateed with 0 or a negative number): ");
    max = 0;
    while(n>0)
    {
        scanf("%f", &n);
        if (n > max)
            max = n;
    }

    printf("The largest number entered was: %f", max);

    return 0;
}
