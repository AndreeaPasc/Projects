/// Sales commission calculator

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float sales, salary;
    printf("Enter sales in dollars (-1 to end): ");
    scanf("%f", &sales);

    while(sales != -1){
        salary = 200 + 9 * sales / 100;
        printf("Salary is: $%.2f", salary);

        printf("\n\nEnter sales in dollars (-1 to end): ");
        scanf("%f", &sales);
    }
    return 0;
}
