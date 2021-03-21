/// Sides of a triangle

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    printf("Enter three sides of a triangle: ");
    scanf("%d %d %d", &a, &b, &c);

    if(a < b + c){
        if(b < a + c){
            if(c < a + b)
                printf("%d, %d, %d can be sides of a triangle", a, b, c);
             else
                printf("%d, %d, %d cannot be sides of a triangle", a, b ,c);
        }
        else
             printf("%d, %d, %d cannot be sides of a triangle", a, b ,c);
    } else
        printf("%d, %d, %d cannot be sides of a triangle", a, b ,c);
    return 0;
}
