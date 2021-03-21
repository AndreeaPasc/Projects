#include <stdio.h>
#include <stdlib.h>

int main()
{
    int month, day, year;
    printf("Enter a date: ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("Ypu entered the date %d%d%d", year, month, day);
    return 0;
}
