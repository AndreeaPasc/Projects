/// Odd or even


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;

    printf("Enter a number: ");
    scanf("%d", &a);

    if(a % 2 == 0)
        printf("%d is even", a);
    if(a % 2 != 0)
        printf("%d is odd", a);
    return 0;
}
