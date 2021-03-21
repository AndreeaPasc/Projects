#include <stdio.h>
#include <stdlib.h>

struct date {
    int day, month, year;
};

int compare_dates(struct date d1, struct date d2);

int main() {

    struct date date1, date2;
    int compare;
    printf("Enter the first date: ");
    scanf("%d/%d/%d", &date1.day, &date1.month, &date1.year);

    printf("\nEnter the second date: ");
    scanf("%d/%d/%d", &date2.day, &date2.month, &date2.year);

    compare =compare_dates(date1, date2);

    if(compare<0)
    {
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d",
               date1.month, date1.day, date1.year, date2.month, date2.day, date2.year);
    } else if(compare>0)
    {
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d",
              date2.month, date2.day, date2.year, date1.month, date1.day, date1.year);
    } else printf("Both dates are the same.");
    return 0;
}

int compare_dates(struct date d1, struct date d2)
{
    if (d1.year < d2.year)
        return -1;
    else if (d1.year > d2.year)
        return 1;
    else if (d1.month < d2.month)
        return -1;
    else if (d1.month > d2.month)
        return 1;
    else if (d1.day < d2.day)
        return -1;
    else if (d1.day > d2.day)
        return 1;
    else /* dates are equal */
        return 0;
}