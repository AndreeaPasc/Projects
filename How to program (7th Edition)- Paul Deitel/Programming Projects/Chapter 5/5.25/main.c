/// finding the minimum

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b, int c);

int main()
{
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("The minimum is: %d", min(a, b, c));
    return 0;
}

int min(int a, int b, int c){
    int min = INT_MAX;
    if(a < b && a < c)
        min = a;
    if(b < a && b < c)
        min = b;
    if(c < a && c < b)
        min = c;
    return min;
}
