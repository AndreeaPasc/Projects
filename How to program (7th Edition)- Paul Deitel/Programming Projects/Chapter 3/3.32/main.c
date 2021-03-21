/// Square of asterisks

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
        while(length < size)
        {
            printf("*");
            length++;
        }
        height++;
        printf("\n");
    }
    return 0;
}
