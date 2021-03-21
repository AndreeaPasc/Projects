/// Diameter, circumference and area of a circle

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float radius;
    printf("Enter the radius of a circle: ");
    scanf("%f", &radius);

    printf("The diameter is %f\n", 2 * radius);
    printf("The circumference is %f\n", 2 * radius * 3.14159);
    printf("The radius is %f", 3.14159 * radius * radius);
    return 0;
}
