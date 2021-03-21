#include <stdio.h>
#include <stdlib.h>

int main()
{
    int integer1, integer2, integer3, integer4, max, min, max1, max2, min1, min2;
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &integer1, &integer2, &integer3, &integer4);

    if(integer1>integer2)
    {
        max1=integer1;
        min1=integer2;
    }
    else
    {
        max1=integer2;
        min1=integer1;
    }

    if(integer3>integer4)
    {
        max2=integer3;
        min2=integer4;
    }
    else
    {
        max2=integer4;
        min2=integer3;
    }

    if(max1>max2)
        max=max1;
    else
        max=max2;

    if(min1<min2)
        min=min1;
    else
        min=min2;

    printf("Largest: %d", max);
    printf("\nSmallest: %d", min);
    return 0;
}

/*
int min = a, max = a;
b < min && (min = b);
c < min && (min = c);
d < min && (min = d);
b > max && (max = b);
c > max && (max = c);
d > max && (max = d);
*/
