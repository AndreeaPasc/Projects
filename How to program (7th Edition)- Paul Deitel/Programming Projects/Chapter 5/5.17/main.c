/// Multiples

#include <stdio.h>
#include <stdlib.h>

int multiple(int a, int b);

int main()
{
    int a, b;
    printf("Enter 2 integers: ");
    scanf("%d %d", &a, &b);

    if(multiple(a, b) == 1)
        printf("%d is a multiple of %d", b, a);
    else
        printf("%d is not a multiple of %d", b, a);
    return 0;
}

int multiple(int a, int b){
    if(b % a == 0)
        return 1;
    else
        return 0;
}
