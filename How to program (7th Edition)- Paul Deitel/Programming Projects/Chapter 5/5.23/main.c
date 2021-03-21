 /// Time in seconds

#include <stdio.h>
#include <stdlib.h>

int convert(int hours, int minutes, int seconds);

int main()
{
    int hours, minutes, seconds;
    printf("Enter the time(hours/minutes/seconds): ");
    scanf("%d:%d:%d", &hours, &minutes, &seconds);

    printf("The time in seconds is %d ", convert(hours, minutes, seconds));


    int hours2, minutes2, seconds2;
    printf("\nEnter another time(hours/minutes/seconds): ");
    scanf("%d:%d:%d", &hours2, &minutes2, &seconds2);
    printf("The difference between the times is: %d", convert(hours, minutes, seconds) - convert(hours2, minutes2, seconds2));
    return 0;
}

int convert(int hours, int minutes, int seconds){
    int time;
    time = seconds + minutes * 60 + hours * 60 * 60;
    return time;
}
