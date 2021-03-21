/// Recursive exponentiation

#include <stdio.h>
#include <stdlib.h>

int power(int base, int exponent);

int main()
{
    int base, exponent;
    printf("Enter a base and an exponent: ");
    scanf("%d %d", &base, &exponent);

    printf("%d^%d = %d", base, exponent, power(base, exponent));
    return 0;
}

int power(int base, int exponent){
    if(exponent != 0)
        return base * power(base, exponent - 1);
    else
        return 1;
}
