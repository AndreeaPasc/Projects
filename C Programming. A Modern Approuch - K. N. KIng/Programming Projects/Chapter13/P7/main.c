#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int digit, i, ctrl, units;
    char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                       "seventeen", "eighteen", "nineteen"};
    char *tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty",
                     "ninety"};
    char *digits[] = {"one", "two", "three", "four", "five", "six", "seven", "eight",
                        "nine"};

    printf("Enter a two-number digit: ");
    scanf("%d", &digit);

    if(digit>9 && digit<20)
    {
        ctrl = digit%10;
        for(i = 0; i<11; i++)
            if(ctrl == i)
                printf("%s", teens[i]);
    }
    else
        if(digit>19)
        {
            ctrl = digit/10-2;
            units = digit%10-1;
            for(i=0; i<8; i++) {
                if (i == ctrl)
                    printf("%s", tens[i]);
            }
            for(i=0; i<9; i++){
                if(i==units)
                    printf(" - %s", digits[i]);
            }


        }


    return 0;
}
