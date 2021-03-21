#include <stdio.h>
#include <stdlib.h>

int main()
{
    float loanAmount, interestRate, monthlyPayment, currentMonth, monthlyInterest;
    int i, n;
    printf("Enter amount of loan: ");
    scanf("%f", &loanAmount);

    printf("Enter interest rate: ");
    scanf("%f", &interestRate);

    printf("Enter monthly payment: ");
    scanf("%f", &monthlyPayment);

    printf("Enter the number of payments: ");
    scanf("%d", &n);

    monthlyInterest = interestRate / 100 /12;

    for(i=1; i<=n; i++)
    {
        currentMonth = loanAmount - monthlyPayment + loanAmount*monthlyInterest;
        printf("The balance after the first month: %.2f\n", currentMonth);
        loanAmount = currentMonth;
    }

    return 0;
}
