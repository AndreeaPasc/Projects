/// Temperature conversions

#include <stdio.h>
#include <stdlib.h>

float celsiusToFahrenheit(float degree);
float FahrenheitToCelsius(float degree);

int main()
{
    float C, F;
    printf("Enter the temperatures in degrees Celsius: ");
    scanf("%f", &C);

    printf("The temperature converted in Fahrenheit is: %f", celsiusToFahrenheit(C));

    printf("\n\nEnter the temperatures in degrees Fahrenheit: ");
    scanf("%f", &F);

    printf("The temperature converted in Celsius is: %f", FahrenheitToCelsius(F));

    printf("\n\n");

    printf("Degree Celsius\tDegree Fahrenheit\n");
    for(C = 0; C <= 100; C++)
        printf("%.0f\t\t%f\n", C, celsiusToFahrenheit(C));

    printf("\n\nDegree Fahrenheit\tDegree Celsius\n");
    for(F = 32; F <= 212; F++)
        printf("%.0f\t\t%f\n", F, FahrenheitToCelsius(F));


    return 0;
}

float celsiusToFahrenheit(float degree){
    return degree * 1.8 + 32;
}

float FahrenheitToCelsius(float degree){
    return (degree - 32) / 1.8;
}
