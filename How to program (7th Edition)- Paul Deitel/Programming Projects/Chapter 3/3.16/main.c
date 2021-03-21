/// Gas mileage

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float gallonsUsed;
    int milesDriven;
    float average;
    float overall = 0;
    unsigned int overallFlag = 0;

    printf("Enter the gallons used (-1 to end): ");
    scanf("%f", &gallonsUsed);


    while(gallonsUsed != -1)
    {
        printf("Enter the miles driven: ");
        scanf("%d", &milesDriven);

        average = milesDriven / gallonsUsed;
        printf("The miles/gallon for this week was %f\n\n", average);

        overall += average;
        overallFlag++;

        printf("Enter the gallons used (-1 to end): ");
        scanf("%f", &gallonsUsed);
    }

    printf("The overall average miles/gallon was: %f", overall / overallFlag);
    return 0;
}
