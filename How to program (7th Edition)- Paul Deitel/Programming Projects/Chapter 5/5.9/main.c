/// Parking charges

#include <stdio.h>
#include <stdlib.h>

float calculateCharges(float charge, float hours);

int main()
{
    float hours, charge, sum = 0, total = 0;
    int car;
    printf("Car\tHours\tCharge\n");
    for(car = 1; car <= 3; car++){
        printf("%d\t", car);
        scanf("%f", &hours);
        printf("\t\t%.2f\n", calculateCharges(charge, hours));
        sum += calculateCharges(charge, hours);
        total += hours;
    }

    printf("TOTAL\t%.2f\t%.2f\t", total, sum);

    return 0;
}

float calculateCharges(float charge, float hours){
    if(hours <= 3){
        charge = 2;
    }
    else if(hours > 3 && hours < 24){
        charge = 2 + (hours - 3) * 0.5;
    }
    else if(hours == 24){
        charge = 10;
    }

    return charge;
}
