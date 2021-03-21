#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Enter a three-digit number: ");
    scanf("%d", &number);

    printf("The reversal is: %3d", number%10*100+number/10%10*10+number/100);
    return 0;
}
