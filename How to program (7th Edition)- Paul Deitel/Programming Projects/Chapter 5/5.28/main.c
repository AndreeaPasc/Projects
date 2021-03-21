/// Reversing digits

#include <stdio.h>
#include <stdlib.h>

int reverse(int number);

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    printf("The number reverse is: %d", reverse(number));
    return 0;
}

int reverse(int number){
    int rev = 0;
    while(number != 0){
        rev = rev * 10 + number % 10;
        number /= 10;
    }
    return rev;
}
