/// Counting 7s

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, aux = 0, count = 0;
    printf("Enter a number: ");
    scanf("%d", &number);

    aux = number;
    while(aux != 0){
        if(aux % 10 == 7)
            count++;
        aux /= 10;
    }

    printf("In the number %d there are %d 7s", number, count);
    return 0;
}
