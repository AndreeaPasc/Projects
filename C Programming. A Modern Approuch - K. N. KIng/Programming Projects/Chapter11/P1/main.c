#include <stdio.h>
#include <stdlib.h>

void pay_amount(int dollarAmount, int *twentyBills, int *tenBills, int *fives, int *oneBillss);

int main() {
    int dollarAmount, tenBills, fiveBills, oneBills, twentyBills;
    printf("The dollar amount: ");
    scanf("%d", &dollarAmount);
    
    pay_amount(dollarAmount, &twentyBills, &tenBills, &fiveBills, &oneBills);
    
    printf("%d requires %d $20 bills, %d $10 bills, %d $5 bills and %d $1 bills.", 
            dollarAmount, twentyBills, tenBills, fiveBills, oneBills);
    
    return 0;
}

void pay_amount(int dollarAmount, int *twentyBills, int *tenBills, int *fiveBills, int *oneBills)
{

    *twentyBills = dollarAmount / 20;
    dollarAmount = dollarAmount - *twentyBills*20;

    *tenBills = dollarAmount / 10;
    dollarAmount = dollarAmount - *tenBills*10;

    *fiveBills = dollarAmount / 5;
    dollarAmount = dollarAmount - *fiveBills*5;

    *oneBills= dollarAmount / 1;
}