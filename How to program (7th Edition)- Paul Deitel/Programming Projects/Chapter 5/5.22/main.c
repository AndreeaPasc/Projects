/// Separating digits

#include <stdio.h>
#include <stdlib.h>

void split(int a);

int main()
{
    int a, b, number;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    /// a)
    printf("The integer part of tye quotient is: %d\n", a / b);

    /// b)
    printf("The integer remainder is: %d\n", a % b);

    /// c)
    printf("Enter a number between 1 and 32767:  ");
    scanf("%d", &number);

    split(number);
    return 0;
}

void split(int a){
    int aux = a;
        if(aux < 10)
            printf("%d", aux);
        else if(aux >= 10 && aux < 100){
            printf("%d  %d", aux / 10, aux % 10);
        }
        else if(aux >= 100 && aux < 1000){
            printf("%d  %d  %d", aux / 100, aux % 100 / 10, aux % 10);
        }
        else if(aux >= 1000 && aux < 10000){
            printf("%d  %d  %d  %d", aux / 1000, aux % 1000 / 100, aux % 100 / 10, aux % 10);
        }
        else if(aux >= 10000 && aux <= 32767){
            printf("%d  %d  %d  %d  %d", aux / 10000, aux / 10000 % 1000, aux % 1000 / 100, aux % 100 / 10, aux % 10);
        }

    }
