/// Factorial

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /// a)
    int number, counter = 1, factorial = 1;
    printf("Enter a number: ");
    scanf("%d", &number);

    while(counter <= number){
        factorial = factorial * counter;
        counter++;
    }

    printf("%d! = %d", number, factorial);

    /// b)
    factorial = 1;
    counter = 1;
    float e = 1;
    while(counter <= 10){
        factorial = factorial * counter;
        e = e + 1 / (float) factorial;
        counter++;
    }
    printf("\ne = %f", e);

    /// c)
    factorial = 1;
    counter = 1;
    e = 1;
    int x, power = 1;
    printf("\nEnter a number: ");
    scanf("%d", &x);
    while(counter <= 10){
        factorial = factorial * counter;
        power = power * x;
        e = e + power / (float) factorial;
        counter++;
    }

    printf("e^%d = %f", x, e);
    return 0;
}
