/// Even or odd

#include <stdio.h>
#include <stdlib.h>

int even(int number);

int main()
{
    int a;
    printf("Enter a number (-1 to end): ");
    scanf("%d", &a);

    while(a != -1){
        if(even(a) == 1)
            printf("%d is even", a);
        else
            printf("%d is odd", a);

        printf("\n\nEnter a number (-1 to end): ");
        scanf("%d", &a);
    }
    return 0;
}

int even(int number){
    if(number % 2 == 0)
        return 1;
    else
        return 0;
}
