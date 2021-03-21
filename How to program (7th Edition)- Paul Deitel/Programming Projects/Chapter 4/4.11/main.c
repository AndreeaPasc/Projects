/// Find the smallest

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n, number, i, min = INT_MAX;
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &number);
        if(number < min)
            min = number;
    }

    printf("The smallest number is: %d", min);
    return 0;
}
