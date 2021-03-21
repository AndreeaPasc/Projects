#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RADIUS 10
#define FRACTION 4.0f / 3.0f

int main()
{
    float volume;

    volume = FRACTION * M_PI * RADIUS * RADIUS * RADIUS;
    printf("The volume is: %f", volume);
    return 0;
}
