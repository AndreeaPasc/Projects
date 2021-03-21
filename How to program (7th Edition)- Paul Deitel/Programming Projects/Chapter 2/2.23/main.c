/// Largest and smallest number

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, max, min;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if(a > b){
        max = a;
        min = b;
    }
    if(a < b){
        min = a;
        max = b;
    }
    if(max > c)
        printf("%d is the largest\n", max);
    if(max < c)
        printf("%d is the largest\n", c);
    if(min < c)
        printf("%d is the smallest\n", min);
    if(min > c)
        printf("%d is the smallest\n", c);

    return 0;
}
