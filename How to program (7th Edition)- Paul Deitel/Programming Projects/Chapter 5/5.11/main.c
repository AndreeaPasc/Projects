/// Rounding numbers

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int roundToInteger(float number);
float roundToTenths(float number);
float roundToHundreths(float number);
float roundToThousandths(float number);

int main()
{
    float number;
    printf("Enter a number (-1 to end): ");
    scanf("%f", &number);

    while(number != -1){
        printf("The original number is %f\n", number);
        printf("The number rounded to integer is %d\n", roundToInteger(number));
        printf("The number rounded to tenths is %f\n", roundToTenths(number));
        printf("The number rounded to hundreths is %f\n", roundToHundreths(number));
        printf("The number rounded to thousandths is %f\n\n", roundToThousandths(number));
        printf("Enter a number (-1 to end): ");
        scanf("%f", &number);
    }
    return 0;
}

int roundToInteger(float number){
    number = floor(number + 0.5);
    return number;
}

float roundToTenths(float number){
    number = floor(number * 10 + 0.5) / 10;
    return number;
}

float roundToHundreths(float number){
    number = floor(number *100 + 0.5) / 100;
    return number;
}

float roundToThousandths(float number){
    number = floor(number * 1000 + 0.5) / 1000;
    return number;
}
