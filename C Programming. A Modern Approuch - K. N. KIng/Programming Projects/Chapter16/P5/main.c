#include <stdio.h>
#include <stdlib.h>

#define HOUR 60
#define NUM_FLIGHTS ((int) (sizeof(flights) / sizeof(flights[0])))

struct times { int departure, arrival; };

int main(void)
{
    int hour, minute, input_time, prev, curr;

    /*  Arrival Times       Departure Times */
    struct times flights[] = {{(HOUR *  8)     ,   (HOUR * 10) + 16},
                              {(HOUR *  9) + 43,   (HOUR * 11) + 52},
                              {(HOUR * 11) + 19,   (HOUR * 13) + 31},
                              {(HOUR * 12) + 47,   (HOUR * 15)     },
                              {(HOUR * 14)     ,   (HOUR * 16) + 8 },
                              {(HOUR * 15) + 45,   (HOUR * 17) + 55},
                              {(HOUR * 19)     ,   (HOUR * 21) + 20},
                              {(HOUR * 21) + 45,   (HOUR * 23) + 58}};

    printf("\nEnter a 24-hour time: ");
    scanf("%2d:%2d", &hour, &minute);

    input_time = (hour * HOUR) + minute;


    for (prev = 0, curr = 1; curr < NUM_FLIGHTS; prev++, curr++)
        if ((abs(input_time - flights[curr].departure)) >=
            (abs(input_time - flights[prev].departure)))
            break;

    printf("Closest Flight\nDeparts: %.2d:%.2d  Arrives: %.2d:%.2d\n",
           flights[prev].departure / HOUR,
           flights[prev].departure % HOUR,
           flights[prev].arrival / HOUR,
           flights[prev].arrival % HOUR);

    return 0;
}