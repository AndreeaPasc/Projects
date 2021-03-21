#include <stdio.h>
#include <stdlib.h>

void reduce(int numerator, int denominator, int *reduce_numerator, int *reduced_denominator);

int main() {

    int numerator, denominator, n1, n2;
    printf("Enter a fraction: ");
    scanf("%d/%d", &numerator, &denominator);

    reduce(numerator, denominator, &n1, &n2);

    printf("In lowest terms: %d/%d", n1, n2);
    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
    int n1 = denominator;
    int n2 = numerator;

    while(n2>0)
    {
        int remainder  = n1 % n2;
        n1 = n2;
        n2 = remainder;
    }

    int gcd = n1;
    *reduced_numerator = numerator/gcd;
    *reduced_denominator = denominator/gcd;

}