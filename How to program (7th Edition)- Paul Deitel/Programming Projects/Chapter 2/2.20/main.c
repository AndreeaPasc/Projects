/// Diameter, circumference and area of a circle

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int radius;
    printf("Enter the radius of a circle: ");
    scanf("%d", &radius);

    printf("The diameter is %d\n", 2*radius);
    printf("The circumference is %f\n", 2*3.14159*radius);
    printf("The area is %f\n", 3.14159*radius*radius);
    return 0;
}
