#include <stdio.h>
#include <stdlib.h>

int main()
{
    int days, start, end=7,startWeek, i;
    printf("Enter number of days in month: ");
    scanf("%d", &days);

    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &startWeek);

    start = startWeek;


    for(i=1; i<=days+startWeek-1 ; i++)
    {

        if(i>=start)
        {

            if(i<=end)
                printf("%2d ", i-startWeek+1);
            else
            {
                printf("\n%2d ", i-startWeek+1);
                end += 7;
            }

        }
        else
            printf("   ");

    }
    return 0;
}
