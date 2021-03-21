/// Target-heart-rate calculator

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int birthDay, birthMonth, birthYear, month, day, year, age, maxRate;
    float targetRate;
    printf("Enter your birthday: ");
    scanf("%d/%d/%d", &birthDay, &birthMonth, &birthYear);
    printf("Enter the current date: ");
    scanf("%d/%d/%d", &day, &month, &year);

    if(birthMonth < month)
        age = year - birthYear;
    else if(birthMonth == month){
            if(birthDay <= day)
                age = year - birthYear;
    }
    else if(birthMonth > month)
        age = year - birthYear - 1;

    maxRate = 220 - age;

    printf("Your age in years is: %d\n", age);
    printf("Your maximum heart rate is: %d\n", maxRate);
    printf("Your target heart rate is: %.2f - %.2f", 50 * (float) maxRate / 100, 85 * (float) maxRate / 100);
    return 0;
}
