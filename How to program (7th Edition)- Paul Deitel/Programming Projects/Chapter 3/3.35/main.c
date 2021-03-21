/// Printing the deimal eqivalent of a binary number

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int binary, aux, decimal = 0, power = 1;
    printf("Enter a 5-digit binary number: ");
    scanf("%d", &binary);

    aux = binary;
    while(aux != 0){
        decimal = decimal + aux % 10 * power;
        power = power * 2;
        aux /= 10;
    }

    printf("%d in decimal is %d", binary, decimal);
    return 0;
}
