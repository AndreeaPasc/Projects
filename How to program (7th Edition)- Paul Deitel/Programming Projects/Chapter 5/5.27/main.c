/// Prime numbers

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void prime(int number);

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    prime(number);

    int i;
    for(i = 1; i <= 10000; i++)
    {
        prime(i);
    }
    return 0;
}

void prime(int number)
{
    int flag = 1;
    int i;

    if(number == 1)
        flag = 0;
    else
    {
        for(i = 2; i <= sqrt(number); i++)
        {
            if(number % i == 0)
                flag = 0;
        }
    }
    if(flag == 1)
        printf("%d is prime\n", number);
    else
        printf("%d is not prime", number);
}
