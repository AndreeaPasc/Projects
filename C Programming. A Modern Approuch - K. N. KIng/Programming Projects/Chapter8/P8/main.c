#include <stdio.h>
#include <stdlib.h>

int main ()
{

    static int array[5][5];
    int i, j ;
    int max=0, min;
    float average, sum = 0;


    for (i = 0; i < 5; ++i)
    {
        printf("Enter row %d: ", i+1);
        for (j = 0; j < 5; ++j)
        {
            scanf("%d", &array[i][j]);
        }
    }


    for (i = 0; i < 5; ++i)
    {
        printf("\nTotal score student %d: ", i+1);
        for (j = 0; j < 5; ++j)
        {
            sum = sum + array[i][j] ;
        }

        printf("%f ", sum);
        printf("Average student %d: %f", i+1, sum/5);
        sum = 0;
    }

    sum = 0;

    for (j = 0; j < 5; ++j)
    {
        for (i = 0; i < 5; ++i)
        {
            sum = sum + array[i][j];
        }

        printf("\nAverage question %d: %f", j+1, sum/5);
        sum = 0;
    }


      for (j = 0; j < 5; ++j)
    {
        max = 0;
        for (i = 0; i < 5; ++i)
        {
            if(array[i][j]>max)
                max = array[i][j];
        }
        printf("\nHigh score for question %d: %d", j+1, max);

    }

       for (j = 0; j < 5; ++j)
    {
       min = 100;
        for (i = 0; i < 5; ++i)
        {
            if(array[i][j]<min)
                min = array[i][j];
        }
        printf("\nLow score for question %d: %d", j+1, min);

    }
    return 0;
}
