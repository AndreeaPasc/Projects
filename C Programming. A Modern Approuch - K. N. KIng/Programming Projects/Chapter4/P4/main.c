#include <stdio.h>
#include <stdlib.h>

int main()
{
    int decimal, octal, quotient, remainder;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &decimal);

    remainder = decimal % 8;
    octal = remainder;
    decimal = decimal/8;

    remainder = decimal%8;
    octal = remainder * 10 + octal;
    decimal = decimal/8;

    remainder = decimal%8;
    octal = remainder * 100 + octal;
    decimal = decimal/8;

    remainder = decimal%8;
    octal = remainder * 1000 + octal;
    decimal = decimal/8;

    remainder = decimal%8;
    octal = remainder * 10000 + octal;
    decimal = decimal/8;

    printf("In octal, your number is %.5d", octal);
    return 0;
}
