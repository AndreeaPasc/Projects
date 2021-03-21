#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dollarAmount, twentyBills, tenBills, fiveBills, oneBills;

    printf("The dollar amount = ");
    scanf("%d", &dollarAmount);

    twentyBills = dollarAmount / 20;
    dollarAmount = dollarAmount - twentyBills*20;

    tenBills = dollarAmount / 10;
    dollarAmount = dollarAmount - tenBills*10;

    fiveBills = dollarAmount / 5;
    dollarAmount = dollarAmount - fiveBills*5;

    oneBills = dollarAmount / 1;

    printf("%d requires %d $20 bills, %d $10 bills, %d $5 bills and %d $1 bills.", dollarAmount, twentyBills,
            tenBills, fiveBills, oneBills);

    return 0;
}
