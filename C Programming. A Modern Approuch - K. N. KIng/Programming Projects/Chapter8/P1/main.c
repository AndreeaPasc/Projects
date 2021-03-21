#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    bool digit_seen[10] = {false};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    printf("Repteated digit(s): \n");
    while(n>0)
    {
        digit = n%10;
        if(digit_seen[digit])
            printf("%d ", digit);
        digit_seen[digit] = true;

        n/=10;
    }

    return 0;
}
