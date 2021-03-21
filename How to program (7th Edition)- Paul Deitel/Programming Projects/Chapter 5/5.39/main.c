/// Recursive gcd

#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y);

int main()
{
    int number1, number2;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &number1, &number2);

    printf("Their GCD is: %d", gcd(number1, number2));
    return 0;
}

int gcd(int x, int y){
    if(y == 0)
        return x;
    else
        return gcd(y, x % y);
}
