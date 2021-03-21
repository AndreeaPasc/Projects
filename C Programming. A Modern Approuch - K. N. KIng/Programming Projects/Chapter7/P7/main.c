#include <stdio.h>
#include <stdlib.h>

int main()
{
    float nom1, nom2, denom1, denom2;
    char operation;
    float n;

    printf("Enter two fractions: ");
    scanf("%f/%f %f/%f", &nom1, &denom1, &nom2, &denom2);

    printf("Enter an operation: ");
    operation = getche();


        switch(operation)
        {
        case '+':
            n = nom1/denom1+nom2/denom2;
            break;
        case '-':
            n = nom1/denom1-nom2/denom2;
            break;
        case '*':
            n = (nom1/denom1)*(nom2/denom2);
            break;
        case '/':
            n = (nom1/denom1)/(nom2/denom2);
            break;
        default:
            printf("You entered an invalid operation.");
            break;
        }

    printf("\n%f", n);


    return 0;
}
