/// Calculating the product of odd integers

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, product = 1;

    for(i = 1; i <= 15; i += 2){
        product *= i;
    }

    printf("product = %d", product);
    return 0;
}
