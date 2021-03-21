#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ten, unit, digit;

    printf("Enter a two-number digit: ");
    scanf("%d", &digit);

    if(digit<20)
    {
        switch(digit)
        {
            case 10: printf("Ten"); break;
            case 11: printf("Eleven"); break;
            case 12: printf("Twelve"); break;
            case 13: printf("Thirteen"); break;
            case 14: printf("Fourteen"); break;
            case 15: printf("Fifteen"); break;
            case 16: printf("Sixteen"); break;
            case 17: printf("Seventeen"); break;
            case 18: printf("Eighteen"); break;
            case 19: printf("Nineteen"); break;
        }
    }

    if (digit>19)
    {

        ten=digit/10;
        unit=digit%10;

        switch(ten)
        {
        case 2 :
            printf("Twenty");
            break;
        case 3 :
            printf("Thirty");
            break;
        case 4 :
            printf("Forty");
            break;
        case 5 :
            printf("Fifty");
            break;
        case 6 :
            printf("Sixty");
            break;
        case 7 :
            printf("Seventy");
            break;
        case 8 :
            printf("Eighty");
            break;
        case 9 :
            printf("Ninety");
            break;
        }

        switch(unit)
        {
        case 0 :
            printf("");
            break;
        case 1 :
            printf("-one");
            break;
        case 2 :
            printf("-two");
            break;
        case 3 :
            printf("-three");
            break;
        case 4 :
            printf("-four");
            break;
        case 5 :
            printf("-five");
            break;
        case 6 :
            printf("-six");
            break;
        case 7 :
            printf("-seven");
            break;
        case 8 :
            printf("-eight");
            break;
        case 9 :
            printf("-nine");
            break;
        }

    }
    return 0;
}
