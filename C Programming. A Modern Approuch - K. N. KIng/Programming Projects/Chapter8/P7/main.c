#include <stdio.h>

int main ()
{

    static int array[5][5];
    int i, j, sum = 0;


    for (i = 0; i < 5; ++i)
    {
        printf("Enter row %d: ", i+1);
        for (j = 0; j < 5; ++j)
        {
            scanf("%d", &array[i][j]);
        }
    }

    printf("\nRow totals: ");
    for (i = 0; i < 5; ++i)
    {
        for (j = 0; j < 5; ++j)
        {
            sum = sum + array[i][j] ;
        }

        printf("%d ", sum);
        sum = 0;

    }
    sum = 0;
    printf("\nColumn totals: ");
    for (j = 0; j < 5; ++j)
    {
        for (i = 0; i < 5; ++i)
        {
            sum = sum + array[i][j];
        }

        printf("%d ", sum);
        sum = 0;

    }
    return 0;
}
