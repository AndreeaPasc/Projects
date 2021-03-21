#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0, n, flag=0;
    char command;

    printf("This program prints a table of squares. \n");
    printf("Enter a number of entries in table: ");
    scanf("%d", &n);

numbers:
    {
        flag = 0;
        for(i=i+1; i<=n; i++)
        {
            printf("%10d%10d\n", i, i*i);
            flag++;
            if (flag==24)
            {
                printf("Press Enter to continue...\n");

                command = getche();

                goto numbers;
            }
        }
    }


    return 0;
}

