#include <stdio.h>
#include <stdlib.h>

int main()
{
    float income, tax;

    printf("Enter the amount of taxable income: ");
    scanf("%f", &income);

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

    printf("The tax due is: %.2f", tax);
    return 0;
}
