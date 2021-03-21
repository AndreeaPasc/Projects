#include <stdio.h>
#include <stdlib.h>

int main()
{
    int departure[8]= {480, 583, 673, 767, 840, 945, 1140, 1305};
    int arrival[8]= {616, 712, 811, 900, 968, 1075, 280, 1438};
    int hour, minute, time, i=0, j, maxmin, maxhour;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);

    time = hour*60+minute;

    int max;

    while(i<8)
    {
        if(time<(departure[i]+departure[i+1])/2)
        {
            max = departure[i];
            break;
        }
        else
        {
            max = departure[i+1];
            j=i+1;
        }
        i++;
    }
    maxhour=max/60;
    maxmin=max-maxhour*60;
    printf("Closest departure time is %d:%d, arriving at %d:%.2d.", maxhour, maxmin, arrival[j]/60, arrival[j]-(arrival[j]/60)*60);


    return 0;
}
