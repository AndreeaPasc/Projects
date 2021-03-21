#include <stdio.h>
#include <stdlib.h>

void multiplication(int a, int b);
void responses(int flag);
void performance(int good, int bad);
void difficulty(int level);

int main()
{
    int level;
    printf("Choose between difficulty 1 or 2.");
    scanf("%d", &level);

    if(level == 1)
    {
        difficulty(1);
    }
    else
        difficulty(2);
    return 0;
}

void difficulty(int level)
{
    switch(level)
    {
    case 1:
    {
        int number1, number2;;
        number1 = rand() % 10;
        number2 = rand() % 10;

        multiplication(number1, number2);
    }
    break;

    case 2:
    {
        int number1, number2;;
        number1 = rand() % 100;
        number2 = rand() % 100;

        multiplication(number1, number2);
    }
    break;
    }
}

void multiplication(int a, int b)
{
    static int i = 2;
    int bad = 0, good = 0;
    int result;
    printf("How much is %d times %d?\n", a, b);
    scanf("%d", &result);
    while(i <= 10)
    {
        if(result == (a * b))
        {
            good++;
            responses(1);
            a = rand() % 10;
            b = rand() % 10;
            printf("How much is %d times %d?\n", a, b);
            scanf("%d", &result);

        }
        else
        {
            bad++;
            responses(0);
            a = rand() % 10;
            b = rand() % 10;
            printf("How much is %d times %d?\n", a, b);
            scanf("%d", &result);
        }
        i++;
    }
    performance(good, bad);
}

void responses(int flag)
{
    int choice;
    choice = rand() % 4;
    if(flag == 1)
    {
        switch(choice)
        {
        case 0:
            printf("Very good!\n");
            break;
        case 1:
            printf("Excellent!\n");
            break;
        case 2:
            printf("Nice work!\n");
            break;
        case 3:
            printf("Keep up the good work!\n");
            break;
        }
    }
    else
    {
        switch(choice)
        {
        case 0:
            printf("No. Please try again.\n");
            break;
        case 1:
            printf("Wrong. Try once more.\n");
            break;
        case 2:
            printf("Don't give up!\n");
            break;
        case 3:
            printf("No. Keep trying.\n");
            break;
        }
    }
}

void performance(int good, int bad)
{
    int result_good, result_bad;
    result_good = good * 10;
    result_bad = bad * 10;
    if(result_good <= 75)
        printf("Please ask your teacher for extra help.\n");
    else
        printf("Congratulations, you are ready to go to the next level!\n");
}
