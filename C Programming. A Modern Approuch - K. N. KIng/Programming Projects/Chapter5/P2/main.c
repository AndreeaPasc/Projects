#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hour, minute;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);

    if(hour<=12)
        printf("Equivalent 12-hour time: %.2d:%.2d", hour, minute);
    else
    {

        switch(hour)
        {
        case 13 :
            hour=1;
            break;
        case 14 :
            hour=2;
            break;
        case 15 :
            hour=3;
            break;
        case 16 :
            hour=4;
            break;
        case 17 :
            hour=5;
            break;
        case 18 :
            hour=6;
            break;
        case 19 :
            hour=7;
            break;
        case 20 :
            hour=8;
            break;
        case 21 :
            hour=9;
            break;
        case 22 :
            hour=10;
            break;
        case 23 :
            hour=11;
            break;
        case 24 :
            hour=0;
            break;
        default :
            printf("You entered an invalid hour.");
        }
        printf("Equivalent 12-hour time: %.2d:%.2d", hour, minute);
    }

    return 0;
}
