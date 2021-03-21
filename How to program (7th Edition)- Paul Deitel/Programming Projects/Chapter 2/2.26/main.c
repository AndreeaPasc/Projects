/// Determining whether one number is a multiple of the other

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &a, &b);

    if(a % b == 0)
        printf("%d is a multiple of %d", a, b);
    if(a % b != 0)
        printf("%d is not a multiple of %d", a, b);

    return 0;
}
