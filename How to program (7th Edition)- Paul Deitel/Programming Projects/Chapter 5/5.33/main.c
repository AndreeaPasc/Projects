/// Guess the number modified

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numberRandom, number, play = 1, count = 0;
    printf("I have a number between 1 and 1000.\nCan you guess my number?\nPlease type your first guess.");
    scanf("%d", &number);
    numberRandom = rand() % 1000 + 1;

    while(play == 1)
    {
        if(number == numberRandom)
        {
            if(count < 10)
                    printf("You know the secret!\n");
                else
                    printf("You should be able to do better.\n");

            printf("Excellent. You guessed the number!\nWould you like to play again (y or n)?");
            scanf("%d", &play);
            if(play != 0)
            {
                printf("\n\nI have a number between 1 and 1000.\nCan you guess my number?\nPlease type your first guess.");
                scanf("%d", &number);
                numberRandom = rand() % 1000 + 1;
            }
        }
        else if(number < numberRandom)
        {
            count++;
            printf("Too low. Try again.");
            scanf("%d", &number);
        }
        else if(number > numberRandom)
        {
            count++;
            printf("Too high. Try again.");
            scanf("%d", &number);
        }
    }

    return 0;
}
