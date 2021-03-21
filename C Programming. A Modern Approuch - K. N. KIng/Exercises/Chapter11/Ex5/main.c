#include <stdio.h>
#include <stdlib.h>

void split_time(long total_sec, int *hr, int *min, int *sec);

int main() {
    long total_sec;
    int hr, min, sec;
    printf("Enter the number of seconds from midnight: ");
    scanf("%li", &total_sec);

    split_time(total_sec, &hr, &min, &sec);

    printf("The time is: %2.2d:%2.2d:%2.2d", hr, min, sec);
    return 0;
}

void split_time(long total_sec, int *hr, int *min, int *sec)
{
    *min = total_sec/60%60;
    *sec = total_sec%60;
    *hr = total_sec/60/60;
}