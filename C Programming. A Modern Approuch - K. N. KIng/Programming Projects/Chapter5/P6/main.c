#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, firstSum, secondSum, total, checkDigit;

    printf("Enter the first (single) digit: ");
    scanf("%d", &d);

    printf("Enter the first group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
    printf("Enter the second group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

    printf("Enter the last digit (check digit): ");
    scanf("%d", &checkDigit);

    firstSum = d+i2+i4+j1+j3+j5;
    secondSum = i1+i3+i5+j2+j4;
    total = 3*firstSum+secondSum;

    if(checkDigit == 9-(total-1)%10)
        printf("VALID");
    else
        printf("NOT VALID");

    return 0;
}
/* int main()
{
    int firstSum, secondSum, total, checkDigit;
    long long digits;
    printf("Enter a UPC: ");
    scanf("%ld", &digits);

    firstSum = digits/100000000000 + digits/1000000000%10 + digits/10000000%10 + digits/100000%10+digits/1000%10+digits/10%10;
    secondSum = digits/10000000000%10 + digits/100000000%10+digits/1000000%10+digits/10000%10+digits/100%10;
    total = 3*firstSum+secondSum;

    checkDigit = digits%10;


    if(checkDigit == 9-(total-1)%10)
        printf("VALID");
    else
        printf("NOT VALID");

    return 0;
}
*/

