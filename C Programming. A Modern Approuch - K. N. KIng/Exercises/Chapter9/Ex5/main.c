#include <stdio.h>

int num_of_digits(int n)
{
    int digits = 0;
    while(n)
    {
        digits++;
        n/=10;
    }

    return printf("The number of digits is: %d", digits);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    num_of_digits(n);

    return 0;
}