/// Bar chart printing program

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, i, k = 1;

    while(k != 6){
    printf("Enter a number between 1 and 30: ");
    scanf("%d", &number);

    for(i = 1; i <= number; i++)
        printf("*");
    printf("\n");
    k++;
    }
    return 0;
}
