#include <stdio.h>
#include <stdlib.h>

int main()
{
    long i;
    int n;

    printf("This program prints a table of squares. \n");
    printf("Enter a number of entries in table: ");
    scanf("%l", &n);

    for(i=1;i<=n;i++)
        printf("%10d%10d\n", i, i*i);
    return 0;
}