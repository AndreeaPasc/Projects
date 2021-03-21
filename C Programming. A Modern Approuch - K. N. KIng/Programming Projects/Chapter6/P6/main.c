#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, square;

    printf("Enter a number: ");
    scanf("%d", &n);

    for(i=1; i<n, square<=n ;i++)
    {
        square = i*i;
        if(square%2==0)
            printf("%d\n", square);

    }
    return 0;
}
