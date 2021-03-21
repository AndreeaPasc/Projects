/// Body mass index calculator

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int weight, BMI;
    float height;
    printf("Enter your weight in kg: ");
    scanf("%d", &weight);

    printf("Enter your height in m: ");
    scanf("%f", &height);

    BMI = weight / (height * height);

    printf("Your BMI is %d. \n\n", BMI);
    printf("BMI VALUES\n");
    printf("Underweight: less than 18.5\n");
    printf("Normal tbetween 18.5 and 24.9\n");
    printf("Overweight: between 25 and 29.9\n");
    printf("Obese: 30 or greatrer");
    return 0;
}
