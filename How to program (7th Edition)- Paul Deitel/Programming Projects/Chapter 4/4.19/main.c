/// Calculating sales

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    float quantity, sum = 0;
    printf("Enter the product number: ");
    scanf("%d", &number);

    switch(number){
        case 1 : printf("The retail price is $2.98"); break;
        case 2 : printf("The retail price is $4.50"); break;
        case 3 : printf("The retail price is $9.98"); break;
        case 4 : printf("The retail price is $4.49"); break;
        case 5 : printf("The retail price is $6.87"); break;
        default : printf("We do not have that product."); break;
    }

    printf("\nEnter the quantity sold for the day: ");
    scanf("%f", &quantity);

    switch(number){
        case 1 : sum = sum + quantity * 2.98; break;
        case 2 : sum = sum + quantity * 4.50; break;
        case 3 : sum = sum + quantity * 9.98; break;
        case 4 : sum = sum + quantity * 4.49; break;
        case 5 : sum = sum + quantity * 6.87; break;
        default : printf("We do not have that product."); break;
    }

    printf("%d sold %f product last week", number, sum * 7);

    return 0;

    }
