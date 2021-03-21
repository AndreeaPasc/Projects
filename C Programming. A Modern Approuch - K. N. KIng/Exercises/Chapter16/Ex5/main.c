#include <stdio.h>
#include <stdbool.h>

struct date{
    int day, month, year;
};

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

int main() {

    return 0;
}

int day_of_year(struct date d){
    bool leap_year;
    int i, months[12] = { /* Jan Feb Mar Apr May Jun */
                             31, 28, 31, 30, 31, 30,
                          /* Jul Aug Sep Oct Nov Dec */
                             31, 31, 30, 31, 30, 31 };
    if(d.year % 4!=0)
        leap_year = false;
    else if(d.year % 100 != 0)
        leap_year = true;
    else if(d.year % 400 != 0)
        leap_year = false;
    else
        leap_year = true;

    if(leap_year == true)
        months[1] = 29;

    for(i=0; i<d.month - 1; i++)
        d.day += months[i];

    return d.day;
}

int compare_dates(struct date d1, struct date d2)
{
    if(d1.year < d2.year)
        return -1;
    else if(d1.year > d2.year)
        return 1;
    else if(d1.month < d2.month)
        return -1;
    else if(d1.month > d2.month)
        return 1;
    else if(d1.day < d2.day)
        return -1;
    else if(d1.day > d2.day)
        return 1;
    else return 0;
}
