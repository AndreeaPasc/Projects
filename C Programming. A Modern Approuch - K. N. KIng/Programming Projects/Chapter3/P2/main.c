#include <stdio.h>
#include <stdlib.h>

int main()
{
    int itemNumber, month, day, year;
    float unitPrice;

    printf("Enter item number: ");
    scanf("%d", &itemNumber);

    printf("Enter unit price: ");
    scanf("%f", &unitPrice);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("\nItem\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%d\t\t$%-4.2f\t\t%d/%d/%d", itemNumber, unitPrice, month, day, year);
    return 0;
}
