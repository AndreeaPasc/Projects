/// Find the two largest numbers

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int count = 1;
    int number, max = 0, max2 = 0;

    while(count <= 10){
        printf("Enter a number: ");
        scanf("%d", &number);

        if(number > max){
            max2 = max;
            max = number;
        }
        else if(number > max2)
            max2 = number;

        count++;
    }

    printf("The largest number is: %d", max);
    printf("\nThe second largest number is: %d", max2);
    return 0;
}
