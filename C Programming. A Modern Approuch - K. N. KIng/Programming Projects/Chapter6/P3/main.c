#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numerator, denominator, remainder, gcd, n1, n2;
    printf("Enter a fraction: ");
    scanf("%d/%d", &numerator, &denominator);

    n1 = denominator;
    n2 = numerator;

    while(n2>0)
    {
        remainder  = n1 % n2;
        n1 = n2;
        n2 = remainder;
    }

    gcd = n1;
    numerator = numerator/gcd;
    denominator=denominator/gcd;

    printf("In lowest terms: %d/%d", numerator, denominator);
    return 0;
}
