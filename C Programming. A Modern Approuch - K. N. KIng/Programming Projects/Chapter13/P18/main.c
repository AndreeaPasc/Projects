#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int month, day, year;
    char *monthName[] = {"January", "February", "March", "April",
                        "May", "June", "July", "August",
                        "September", "October", "November", "December"};

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("You entered the date: %s %d, %d", monthName[month-1], day, year);
    return 0;
}