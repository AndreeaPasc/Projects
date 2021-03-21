#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FRACTION 4.0f / 3.0f

int main()
{
    float volume, radius;

    printf("Radius = ");
    scanf("%f", &radius);

    volume = FRACTION * M_PI * radius * radius * radius;
    printf("The volume is: %f", volume);
    return 0;
}
