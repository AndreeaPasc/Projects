/// Interest calculator

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float principal, rate, interest;
    unsigned int days;

    printf("Enter loan principal (-1 to end): ");
    scanf("%f", &principal);

    while(principal != -1){
        printf("Enter interest rate: ");
        scanf("%f", &rate);

        printf("Enter term of loan in days: ");
        scanf("%u", &days);

        interest = principal * rate * days / 365;
        printf("The interest charge is: $%.2f", interest);

        printf("\n\nEnter loan principal (-1 to end): ");
        scanf("%f", &principal);
    }
    return 0;
}
