#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, digits, inv=0, aux;
    printf("Enter a number: ");
    scanf("%d", &number);

    aux = number;

    do
    {
        inv = aux%10 + inv*10;
        aux /= 10;
    }while(aux);

    printf("The inverse of the number %d is %d.", number, inv);
    return 0;
}
