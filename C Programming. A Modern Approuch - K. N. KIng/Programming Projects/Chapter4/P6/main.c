#include <stdio.h>
#include <stdlib.h>

int main()
{
    int digits, firstSum, secondSum, total;
    printf("Enter the first 12 digits of a EAN: ");
    scanf("%d", &digits);

    firstSum = digits/10000000000%10 + digits/100000000%10 + digits/1000000%10 + digits/10000%10+digits/100%10+digits%10;
    secondSum = digits/100000000000 + digits/1000000000%10+digits/10000000%10+digits/100000%10+digits/1000%10+ digits/10%10;
    total = 3*firstSum+secondSum;

    printf("Check digit: %d", 9-(total-1)%10);
    return 0;
}
