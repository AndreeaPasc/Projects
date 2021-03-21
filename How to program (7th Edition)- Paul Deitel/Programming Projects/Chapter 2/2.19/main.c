/// Sum, average, product, max, min of 3 values

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, flag;
    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("Sum is %d\n", a+b+c);
    printf("Average is %d\n", (a+b+c)/3);
    printf("Product is %d\n", a*b*c);

    if(a < b)
        flag = a;
    if(a > b)
        flag = b;
    if(flag < c)
        printf("Smallest is %d\n", flag);
    if(flag > c)
        printf("Smallest is %d\n", c);


    if(a > b)
        flag = a;
    if(a < b)
        flag = b;
    if(flag > c)
        printf("Largest is %d\n", flag);
    if(flag < c)
        printf("Largest is %d\n", c);
    return 0;
}
