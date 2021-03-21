#include <stdio.h>

int main() {

    struct fraction{
        int denominator, numerator;
    }f, f1, f2;

    /// a)
    int i;
    int gcd;
    printf("Enter a fraction: ");
    scanf("%d/%d", &f.numerator, &f.denominator);

    for(i=1; i<f.denominator && i<f.numerator; ++i)
    {
        if(f.numerator%i==0 && f.denominator%i==0)
            gcd = i;
    }

    f.numerator = f.numerator / gcd;
    f.denominator = f.denominator / gcd;

    printf("The reduces fraction is: %d/%d.", f.numerator, f.denominator);

    /// b)
    printf("\nEnter two fraction: ");
    scanf("%d/%d %d/%d", &f1.numerator, &f1.denominator, &f2.numerator, &f2.denominator);
    int denominator_sum, numerator_sum;
    numerator_sum = f1.numerator * f2.denominator + f1.denominator*f2.numerator;
    denominator_sum = f1.denominator*f2.denominator;
    printf("\nThe sum is: %d/%d.", numerator_sum, denominator_sum);

    /// d)
    int multiplication_denominator, multiplication_numerator;
    multiplication_numerator = f1.numerator * f2.numerator;
    multiplication_denominator = f1.denominator * f2.denominator;

    printf("\nThe product is: %d/%d.", multiplication_numerator, multiplication_denominator);

    /// c)
    int denominator_sub, numerator_sub;
    numerator_sub = f1.numerator * f2.denominator - f1.denominator*f2.numerator;
    denominator_sub = f1.denominator*f2.denominator;
    printf("\nThe sub is: %d/%d.", numerator_sub, denominator_sub);

    /// e)
    int numerator_division, denominator_division;
    numerator_division = f1.numerator*f2.denominator;
    denominator_division = f1.denominator*f2.numerator;
    printf("\nThe division result is: %d/%d.", numerator_division, denominator_division);


    return 0;
}