/// The sieve of Eratosthenes

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int main()
{
    int array[SIZE], number = 1, flag = 1;
    size_t i;
    array[1] = 0;
    for(i = 2; i < SIZE; i++)
    {
        array[i] = 1;
    }
    while(number != SIZE)
    {
        flag = 1;
        for(i = 2; i < SIZE; i++)
        {
            if(number != i)
            {
                if(number % i == 0)
                {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 0)
            array[number] = 0;
        number++;
    }
    array[1] = 0;
    for(i = 1; i < SIZE; i++)
        printf("%d ", array[i]);
    return 0;
}
