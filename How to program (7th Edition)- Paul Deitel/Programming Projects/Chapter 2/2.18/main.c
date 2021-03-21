/// Comparing integers with the single-selection form of the if statement

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &num1, &num2);

    if(num1 > num2) {
        printf("%d is larger.\n", num1);
    }

    if(num2 > num1) {
        printf("%d is larger.\n", num2);
    }

    if(num1 == num2) {
        printf("The numbers are equal.");
    }
    return 0;
}
