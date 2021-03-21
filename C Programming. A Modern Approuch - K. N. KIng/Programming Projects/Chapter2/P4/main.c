#include <stdio.h>
#include <stdlib.h>

#define TAX 5.0f/100.0f

int main()
{
    float entryAmount, exitAmount;

    printf("Enter an amount: ");
    scanf("%f", &entryAmount);

    exitAmount = TAX * entryAmount + entryAmount;
    printf("With tax added: %.2f", exitAmount);
    return 0;
}
