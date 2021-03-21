#include <stdio.h>
#include <stdlib.h>

int main()
{
    float loanAmount, interestRate, monthlyPayment, currentMonth, monthlyInterest;
    printf("Enter amount of loan: ");
    scanf("%f", &loanAmount);

    printf("Enter interest rate: ");
    scanf("%f", &interestRate);

    printf("Enter monthly payment: ");
    scanf("%f", &monthlyPayment);

    monthlyInterest = interestRate / 100 /12;

    currentMonth = loanAmount - monthlyPayment + loanAmount*monthlyInterest;
    printf("The balance after the first month: %.2f\n", currentMonth);

    currentMonth = currentMonth- monthlyPayment + currentMonth*monthlyInterest;
    printf("The balance after the second month: %.2f\n", currentMonth);

    currentMonth = currentMonth- monthlyPayment + currentMonth*monthlyInterest;
    printf("The balance after the third month: %.2f", currentMonth);
    return 0;
}
