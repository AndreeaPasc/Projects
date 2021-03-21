#include <stdio.h>

float income_tax(float income)
{
    float tax;

    if(income<750)
        tax = .01f*income;
    else
    {
        if(income>=750 && income<2250)
            tax=7.50f + .02f*income;
        else
        {
            if(income>=2250 && income<3750)
                tax = 37.50f + .03f*income;
            else
            {
                if(income>=3750 && income<5250)
                    tax = 82.50 + .04f*income;
                else
                {
                    if(income>=5250 && income<7000)
                        tax = 142.50f+.05f*income;
                    else
                        tax = 230.00f+.06f*income;
                }
            }
        }
    }

    return printf("The tax due is: %.2f", tax);
}

int main() {

    int income;
    printf("Enter the amount of taxable income: ");
    scanf("%d", &income);

    income_tax(income);
    return 0;
}