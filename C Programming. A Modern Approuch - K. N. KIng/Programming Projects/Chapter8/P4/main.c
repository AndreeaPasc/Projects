#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10], i;

    for(i=0; i<(int) sizeof(a)/sizeof(a[0]); i++)
    {
        scanf("%d", &a[i]);
    }

    printf("In reverse order: ");
    for(i=(int) sizeof(a)/sizeof(a[0])-1; i>=0;i--)
        printf(" %d", a[i]);
    printf("\n");
    return 0;
}
