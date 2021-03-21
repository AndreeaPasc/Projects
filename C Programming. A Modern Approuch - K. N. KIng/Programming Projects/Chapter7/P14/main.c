#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x, oldY=1, newY, average, difference;
    newY = oldY;
    printf("Enter a positive number: ");
    scanf("%lf", &x);

    while(fabs(difference)>.00001)
    {
        average = (newY + x/newY)/2;
        oldY = newY;
        newY = average;
        difference = newY - oldY;
    }

    printf("Square root: %lf", average);
    return 0;
}
