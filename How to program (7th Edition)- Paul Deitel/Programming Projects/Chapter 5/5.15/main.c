/// Hypotenuse calculations

#include <stdio.h>
#include <stdlib.h>

double hypotenuse(double a, double b);

int main()
{
    double a, b, c;
    printf("Enter 2 sides of a right triangle: ");
    scanf("%lf %lf", &a, &b);
    c = hypotenuse(a, b);
    printf("Side 1 = %.2lf\nSide 2 = %.2lf\nHypotenuse = %.2lf", a, b, c);
    return 0;
}

double hypotenuse(double a, double b){
    return a * a + b * b;
}
