#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LEN 50

void reverse(char *message);

int main() {
    char message[LEN];
    char input, *p;

    printf("Enter a message: ");
    for(p=&message[0]; p<&message[0] + LEN; p++)
    {
        if ((input = getchar()) == '\n')
            break;
        *p = input;
    }
    *p = '\0';

    reverse(message);
    printf("The reversed message is: %s", message);

    return 0;
}

void reverse(char *message)
{
    char *begin;
    int n = strlen(message);
    char *end;
    char between;

    begin = message;
    end = begin + n - 1;

    while(begin <= end)
    {
        between = *begin;
        *begin = *end;
        *end = between;
        begin++;
        end--;
    }
}