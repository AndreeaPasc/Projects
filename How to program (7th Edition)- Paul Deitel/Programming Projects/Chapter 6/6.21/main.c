/// Airline reservation system

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void seatAssignment(int seats[], int size, int place);

int main()
{
    int planeClass;
    int seats[SIZE] = {0};
    size_t i;
    int full1 = 0, full2 = 0;

    printf("Please type 1 for 'first class'.\nPlease type 2 for 'economy'.");
    scanf("%d", &planeClass);

    if(planeClass == 1)
    {
        for(i = 0; i < 5; i++)
        {
            if(seats[i] == 0)
            {
                full1++;
                seats[i]++;
                break;
            }
            else if(full1 == 5)
            {
                printf("Is it acceptable to be placed in the 'first class'?");
                scanf("%d", &planeClass);
                if(planeClass == 0)
                {
                    seatAssignment(seats, SIZE, planeClass);
                }
                else
                    printf("The next flight leaves in 3 hours");
            }
        }
        printf("You have seat number %d in economy class.", i+1);
    }
    else
    {
        for(i = 5; i < 10; i++)
        {
            if(seats[i] == 0)
            {
                full2++;
                seats[i]++;
                break;
            }
            else if(full2 == 5)
            {
                printf("Is it acceptable to be place in the 'economy class'?");
                scanf("%d", &planeClass);
                if(planeClass == 1)
                    seatAssignment(seats, SIZE, planeClass);
                else
                    printf("The next flight ;eaves in 3 hours.");
            }
        }
        printf("You have seat number %d in first class.", i+1);
    }

    return 0;
}

void seatAssignment(int seats[], int size, int place)
{
    int i;
    if(place == 0)
    {
        for(i = 0; i < 5; i++)
        {
            if(seats[i] == 0){
                seats[i]++;
                break;
            }
            else
                printf("There are no seats left.");
        }
        printf("You have seat number %d in first class.", i+1);
    }
    else
    {
        for(i = 5; i < 10; i++){
            if(seats[i] == 0){
                seats[i]++;
                break;
            }
            else
                printf("There are no seats left.");
        }
        printf("You have seat number %d in economy class.", i+1);
    }
}
