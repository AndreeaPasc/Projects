#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year1, month1, day1, month2, day2, year2, minYear, minMonth, minDay;
    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month1, &day1, &year1);

    minYear = year1;
    minMonth = month1;
    minYear = year1;
    do
    {


        if(year1>year2)
            minYear = year2;
        else
            minYear = year1;

        if(month1>month2)
            minMonth = month2;
        else
            minMonth = month1;

        if(day1>day2)
            minDay = day2;
        else
            minDay = day1;


        year1 = year2;
        month1 = month2;
        day1 = day2;

    }while(year1!=0 && day1!=0 && month1!=0);

    printf("%d/%d/%.2d is the earliest date.", minMonth, minDay, minYear);
    return 0;
}

