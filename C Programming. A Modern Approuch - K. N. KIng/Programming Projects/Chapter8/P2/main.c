#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    bool digit_seen[10] = {false};
    int digit, digits[10]={0,1,2,3,4,5,6,7,8,9}, table[10]={0,0,0,0,0,0,0,0,0,0,0};
    long n, i;


    printf("Enter a number: ");
    scanf("%ld", &n);

    printf("Digit:      ");
    for(i=0; i<10; i++)
        printf("%2d", digits[i]);


    while(n>0)
    {
        digit = n%10;
            table[digit] += 1;
        n/=10;
    }

    printf("\nOccurances: ");
    for(i=0; i<10; i++)
        printf("%2d", table[i]);

    return 0;
}
