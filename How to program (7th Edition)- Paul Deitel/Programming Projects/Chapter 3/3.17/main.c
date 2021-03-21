/// Credit limit calculator

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int account;
    float firstBalance, charges, credit, creditLimit, newBalance;

    printf("Enter account number (-1 to end): ");
    scanf("%d", &account);

    while(account != -1) {
        printf("Enter beginning balance: ");
        scanf("%f", &firstBalance);

        printf("Enter total charges: ");
        scanf("%f", &charges);

        printf("Enter total credits: ");
        scanf("%f", &credit);

        printf("Enter credit limit: ");
        scanf("%f", &creditLimit);

        newBalance = firstBalance + charges - credit;

        if(newBalance > creditLimit)
        {
            printf("Account: \t%d\n", account);
            printf("Credit limit: \t%.2f\n", creditLimit);
            printf("Balance: \t%.2f\n", newBalance);
            printf("Credit Limit Exceeded.\n");
        }

        printf("\n\nEnter account number (-1 to end): ");
        scanf("%d", &account);
    }
    return 0;
}
