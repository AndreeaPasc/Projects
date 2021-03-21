#include <stdio.h>

int digit(int n, int k, int result)
{
    int digits = 0;
    int number;
    number = n;

    while(number)
    {
        digits++;
        number/=10;
    }

    if(k>digits)
        return 0;
    else
    {
        while(k)
        {
            result = n%10;
            k--;
            n/=10;
        }
        return printf("The digit is: %d", result);
    }
}

int main() {
    int n, k, result;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Enter the digit that you want to see: ");
    scanf("%d", &k);

    digit(n, k, result);
    return 0;
}