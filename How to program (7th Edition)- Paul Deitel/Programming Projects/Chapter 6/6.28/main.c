/// Duplicate elimination

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int main()
{
    size_t i, j;
    int array[SIZE], nonDup[SIZE] = {0}, non;

    for(i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 20 + 1;
    }

    printf("The array is: ");
    for(i = 0; i < SIZE; i++)
        printf("%d ", array[i]);

    puts("");

    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            if(i != j)
            {
                if(array[i] != array[j])
                {
                    non = 1;
                }
                else
                {
                    non = 0;
                    break;
                }
            }
        }
        if(non == 1)
        {
            nonDup[i] = array[i];
        }
    }

    for(i = 0; i < SIZE; i++)
    {
        if(nonDup[i] != 0)
        {
            printf("%d ", nonDup[i]);
        }
    }

    return 0;
}
