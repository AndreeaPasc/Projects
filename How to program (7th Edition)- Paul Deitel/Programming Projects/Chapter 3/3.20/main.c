/// Salary calculator

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float rate, salary;
    unsigned int hours;

    printf("Enter # of hours worked (-1 to end): ");
    scanf("%u", &hours);

    while(hours != -1){
        printf("Enter hourly rate of worker ($00.00): ");
        scanf("%f", &rate);

        if(hours > 40){
            salary = 40 * rate + (hours - 40) * (rate + rate / 2);
        }
        else {
            salary = hours * rate;
        }

        printf("Salary is $%.2f", salary);

        printf("\n\nEnter # of hours worked (-1 to end): ");
        scanf("%u", &hours);
    }
    return 0;
}
