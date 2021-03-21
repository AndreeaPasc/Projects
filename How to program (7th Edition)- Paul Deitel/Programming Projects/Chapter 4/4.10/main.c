/// Average a sequence of integers

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, number, i = 0, sum = 0;
    float average;

    scanf("%d", &number);

    while(number != 9999){
        i++;
        sum += number;
        scanf("%d", &number);
    }

    average = (float) sum / i;
    printf("The average of %d numbers is: %.2f", i, average);
    return 0;
}
