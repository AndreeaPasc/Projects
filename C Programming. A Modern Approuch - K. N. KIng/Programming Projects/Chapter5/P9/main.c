#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year1, month1, day1, year2, month2, day2;
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month1, &day1, &year1);

    printf("Enter second year (mm/dd/yy): ");
    scanf("%d/%d/%d", &month2, &day2, &year2);

    if(year1>year2)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d.", month2, day2, year2, month1, day1, year1);
    else
    {
        if(month1>month2)
            printf("%d/%d/%.2d is earlier than %d/%d/%.2d.", month2, day2, year2, month1, day1, year1);
        else
        {
            if(day1>day2)
                printf("%d/%d/%.2d is earlier than %d/%d/%.2d.", month2, day2, year2, month1, day1, year1);

            else
                printf("%d/%d/%.2d is earlier than %d/%d/%.2d.", month1, day1, year1, month2, day2, year2);
        }
    }
    return 0;
}
