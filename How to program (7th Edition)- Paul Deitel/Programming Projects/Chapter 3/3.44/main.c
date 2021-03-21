/// Sides of a right triangle

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    printf("Enter the sides of a triangle: ");
    scanf("%d %d %d", &a, &b, &c);

    if(a * a + b * b == c * c){
        printf("%d, %d, %d are sides of a right triangle", a, b, c);
    }
    else if(a * a + c * c == b * b){
        printf("%d, %d, %d are sides of a right triangle", a, b, c);
    }
    else if(c * c + b * b == a * a){
        printf("%d, %d, %d are sides of a right triangle", a, b, c);
    }
    else
        printf("%d, %d, %d are not sides of a right triangle", a, b, c);
    return 0;
}
