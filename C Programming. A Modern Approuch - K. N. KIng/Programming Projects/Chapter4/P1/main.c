#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    printf("The reversal is: %2d", number%10*10+number/10);
    return 0;
}
