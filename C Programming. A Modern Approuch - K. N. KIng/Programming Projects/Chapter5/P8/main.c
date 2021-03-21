#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hour, minutes, sinceMidnight;

    printf("Enter a time in 24-hour clock: ");
    scanf("%d:%d", &hour, &minutes);

    sinceMidnight = hour*60+minutes;

    if(sinceMidnight<8*60 && sinceMidnight<(8*60+9*60+43)/2)
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.");
    else
    {
        if(sinceMidnight<(9*60+43+11*60+19)/2)
            printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.");
        else
        {
            if(sinceMidnight<(11*60+19+12*60+47)/2)
                printf("Closest departure time is 11:19 a.m., arrival at 1:31 p.m.");
            else
            {
                if(sinceMidnight<(12*60+47+14*60)/2)
                    printf("Closest departure is at 12:47 a.m., arrival at 3:00 p.m.");
                else
                {
                    if(sinceMidnight<(14*60+15*60+45)/2)
                        printf("Closest departure time is 2:00 p.m., arrival at 4:08 p.m.");
                    else
                    {
                        if(sinceMidnight<(15*60+45+19*60)/2)
                            printf("Closest departure time is 3:45 p.m., arrival at 5:55 p.m.");
                        else
                        {
                            if(sinceMidnight<(19*60+21*6+45)/2)
                                printf("Closest departure time is 7:00 p.m., arrival at 9:20 p.m.");
                            else
                            {
                                printf("Closest departure time is 9:45 p.m., arrival at 11:58 p.m.");
                            }
                        }
                    }
                }
            }
        }
    }

return 0;
}

