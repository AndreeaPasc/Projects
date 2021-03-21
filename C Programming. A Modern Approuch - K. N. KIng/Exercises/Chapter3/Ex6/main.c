#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num1, denom1, num2, denom2, result_num, result_denom;

    printf("Enter the first fraction: ");
    scanf("%d / %d", &num1, &denom1);

    printf("\nEnter the second fraction: ");
    scanf("%d / %d", &num2, &denom2);

    result_num = num1*denom2 + num2*denom1;
    result_denom = denom1*denom2;

    printf("\nThe sum is %d/%d", result_num, result_denom);
    return 0;
}
