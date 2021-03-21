/// Perfect numbers

#include <stdio.h>
#include <stdlib.h>

void perfect(int number);

int main()
{
    int number, i;
    printf("Enter a number: ");
    scanf("%d", &number);

    perfect(number);

    printf("\n\n");

    for(i = 1; i <= 1000; i++){
        perfect(i);
    }

    return 0;
}

void perfect(int number){
    int i, sum = 0;
    for(i = 1; i < number; i++){
        if(number % i == 0)
            sum = sum + i;
    }
    if(number == sum)
        printf("%d is a perfect number\n", number);
    else
        printf("%d is not a perfect number\n", number);
}
