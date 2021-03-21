/// Calculating weekly pay

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double managers, hourly, commission, pieceworkers, pay = 0;
    unsigned int i, hours, weekly, product;
    printf("Enter the code of the worker: ");
    scanf("%u", &i);

    switch(i){
        case 1 : printf("Managers are paid $500/week."); break;
        case 2: printf("The hourly workers are paid $10/hour. Enter the number of hours worked: ");
                scanf("%u", &hours);
                pay = 40 * 10 + (hours - 40) * 10 * 1.5;
                printf("The worker is paid: %lf ", pay); break;
        case 3 : printf("Enter the gross weekly sale of a commission worker: ");
                scanf("%u", &weekly);
                pay = 250 + .057 * weekly;
                printf("The commission worker is paid: %lf ", pay); break;
        case 4 : printf("The pieceworker is paid $20/product. Enter the amount of products the pieceworker produced: ");
                scanf("%u", &product);
                pay = product * 20;
                printf("The pieceworker is paid: %lf", pay); break;
        default : printf("You entered an invalid code."); break;
    }
    return 0;
}
