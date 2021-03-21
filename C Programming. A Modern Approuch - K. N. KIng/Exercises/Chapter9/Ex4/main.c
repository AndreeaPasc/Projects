#include <stdio.h>

int day_of_year(int month, int day, int year)
{
    int flag;
    if(year%4==0)
    {
        if(year%100==0)
        {
            if(year%400==0)
                flag = 1;
            else
                flag = 0;
        }
        else
            flag = 1;
    }
    else flag = 0;

    if(flag == 0)
    {
        month--;
        while(month)
        {
            if(month == 2)
                day += 28;
            else
            {
                if(month%2==0)
                    day+=30;
                else
                    day+=31;
            }
            month--;
        }
    }

    else
    {
        month--;
        while(month)
        {
            if(month == 2)
                day += 29;
            else
            {
                if(month%2==0)
                    day+=30;
                else
                    day+=31;
            }
            month--;
        }
    }

    return printf("The day of the year is: %d", day);
}

int main() {
    int day, year, month;

    printf("Enter a day, a month and a year: ");
    scanf("%d %d %d", &day, &month, &year);

    day_of_year(month, day, year);

    return 0;
}