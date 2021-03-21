/// Calculating credit limits

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, credit, balance, i, recession;
    for(i = 0; i < 2; i++){
        printf("Enter the customer's account number: ");
        scanf("%d", &number);

        printf("Enter the customer's credit limit before the recession: ");
        scanf("%d", &credit);

        printf("Enyer the customer's current balance: ");
        scanf("%d", &balance);

        recession = credit / 2;
        printf("New credit limit: %d\n", recession);

        if(balance > recession)
            printf("Balance exceeded the new credit limit.\n\n");
    }
    return 0;
}
