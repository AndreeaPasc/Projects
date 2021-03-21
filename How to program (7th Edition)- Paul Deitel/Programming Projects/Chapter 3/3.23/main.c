/// Finding the largest number

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int counter, number, largest = 0;
    counter = 0;

    while(counter < 10){
        printf("Enter the number of units sold: ");
        scanf("%u",&number);

        if(largest < number)
            largest = number;

        counter++;
    }

    printf("The largest is: %u", largest);
    return 0;
}
