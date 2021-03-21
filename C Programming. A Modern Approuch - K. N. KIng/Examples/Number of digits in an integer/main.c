#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, digits=0;
    printf("Enter a non-negative number: ");
    scanf("%d", &n);

    do
    {
        n /= 10;
        digits++;
    }while(n>0);

    printf("The number has %d digit(s): ", digits);
    return 0;
}
