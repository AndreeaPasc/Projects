/// Exponentiation

#include <stdio.h>
#include <stdlib.h>

int integerPower(int base, unsigned int exponent);

int main()
{
    int base;
    unsigned int exponent;
    int power;
    printf("Enter a base and an exponent: ");
    scanf("%d %u", &base, &exponent);

    power = integerPower(base, exponent);
    printf("%d^%u = %d", base, exponent, power);

    return 0;
}

int integerPower(int base, unsigned int exponent){
    int power = 1;
    int i;
    for(i = 1; i <= exponent; i++)
        power = power * base;
    return power;
}
