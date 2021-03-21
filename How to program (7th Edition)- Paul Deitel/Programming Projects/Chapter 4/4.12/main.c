/// Calculating the sum of even integers

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, sum = 0;
    for(i = 2; i <= 30; i += 2){
        sum += i;
    }

    printf("sum = %d", sum);
    return 0;
}
