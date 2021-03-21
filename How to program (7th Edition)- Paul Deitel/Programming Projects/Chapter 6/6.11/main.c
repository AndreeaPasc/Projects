/// Bubble sort

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int SIZE = 10;
    int a[10] = {2, 6, 4, 8, 1, 12, 89, 68, 45, 37};
    int pass;
    size_t i;
    int hold;
    int test;

    puts("Data items in original order");

    for(i = 0; i < SIZE; i++)
    {
        printf("%4d", a[i]);
    }

    /// bubble sort
    for(pass = 1; pass < SIZE; ++pass)
    {
        test = 0;
        for(i = 0; i < SIZE; i++)
        {
            if(a[i] > a[i+1])
            {
                hold = a[i];
                a[i] = a[i+1];
                a[i+1] = hold;
                test = 1;
            }
        }

        if(test == 0)
            break;
    }

    puts("\nData items in ascending order");
    for(i = 0; i < SIZE; ++i)
    {
        printf("%4d", a[i]);
    }

    puts("");

    return 0;
}
