#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int roll_dice(void)
{
    int die1, die2, sum=0;
    die1 = rand()%6+1;
    die2 = rand()%6+1;
    sum = die1+die2;
    return sum;
}

bool play_game(void)
{
    int sum, point, flag=0;
    printf("\nYou rolled: %d", sum=roll_dice());
    if((sum==7)||(sum==11))
    {
        return true;
    }
    else
        if(sum==2||sum==3||sum==12)
        {
            return false;
        }
        else
        {
            point = sum;
            printf("\nYour point is: %d", point);

            int n = roll_dice();
            printf("\nYou rolled: %d", n);
                while (point != n && n!=7) {
                    printf("\nYou rolled: %d", n);
                    if (point == n) {
                        return true;
                    } else {
                        n = roll_dice();
                        printf("\nYou rolled: %d", n);
                        if(point==n && n!=7)
                            return true;
                        else
                            flag = 0;
                    }
                }
                if(flag==0)
                    return false;
        }
}

int main() {

    srand((unsigned) time(NULL));
    char play;
    int wins=0, losses=0;
    play = 'Y';
    while(play == 'Y')
    {
        if(play_game()==true)
        {
            wins +=1;
            printf("\nYou win!");
        }
        else
        {
            losses+=1;
            printf("\nYou lose!");
        }
        printf("\nPlay again?");
        scanf(" %c", &play);
        play = toupper(play);
    }

    printf("Wins: %d    Losses: %d", wins, losses);
    return 0;
}