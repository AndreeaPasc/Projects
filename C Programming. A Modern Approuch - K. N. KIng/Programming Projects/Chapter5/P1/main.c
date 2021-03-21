#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if(number<=9 && number>=0)
        printf("The number %d has 1 digit.", number);
    else
    {
        if(number<=99 && number>=10)
            printf("The number %d has 2 digits.", number);
        else
        {
            if (number<=999 && number>=100)
                printf("The number %d has 3 digits.", number);
            else
            {
                if(number<=9999 && number>=1000)
                    printf("The number %d has 4 digits.", number);
            }
        }
    }
    return 0;
}
