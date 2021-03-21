/// Hollow square of asterisks

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, length = 0, height = 0;
    printf("Enter the size of your square: ");
    scanf("%d", &size);

    while(height < size)
    {
        length = 0;
        if(height == 0)
        {
            while(length < size)
            {
                printf("*");
                length++;
            }
        }
        else if(height == size - 1)
        {
            length = 0;
            while(length < size)
            {
                printf("*");
                length++;
            }
        }
        else
        {
            printf("*");
            length = 0;
            while(length < size - 2)
            {
                printf(" ");
                length++;
            }
            printf("*");
        }
        height++;
        printf("\n");
    }

    return 0;
}
