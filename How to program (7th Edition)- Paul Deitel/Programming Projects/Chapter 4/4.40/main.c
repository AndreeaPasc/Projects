/// Tax plan alternatives; the "FairTax"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    float expenses, sum = 0;

    printf("Enter your expenses (-1 to end): ");
    while(expenses != -1){
        scanf("%f", &expenses);
        sum += expenses;
    }
    printf("Your estimated fair tax: %f", sum * 0.3);
    return 0;
}
