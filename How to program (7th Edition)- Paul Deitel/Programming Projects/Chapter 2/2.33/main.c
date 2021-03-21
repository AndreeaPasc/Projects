/// Car-pooling savings calculator

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int miles, gasCost, mpg, feePark, tolls;
    printf("The total miles driven per day: ");
    scanf("%d", &miles);

    printf("The cost per gallon of gasoline: $");
    scanf("%d", &gasCost);

    printf("The average miles per gallon: ");
    scanf("%d", &mpg);

    printf("The parking fees per day: $");
    scanf("%d", &feePark);

    printf("The tolls per day: %");
    scanf("%d", &tolls);

    printf("Your daily cost of driving to work is: %d", tolls + feePark + (miles / mpg) * gasCost);
    return 0;
}
