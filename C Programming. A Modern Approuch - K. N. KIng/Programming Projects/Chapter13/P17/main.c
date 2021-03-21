#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define LEN 50

bool is_palindrome(const char *message);

int main() {
    char message[LEN];
    char input, *p;

    printf("Enter a message: ");
    for(p = &message[0]; p < &message[0] + LEN; p++)
    {
        if((input = getchar()) == '\n')
            break;
        *p = input;
    }
    *p = '\0';

    if(is_palindrome(message))
        printf("The message is a palindrome.");
    else
        printf("The message is not a palindrome.");
    return 0;
}

bool is_palindrome(const char *message)
{
    char *begin, *end;
    int n = strlen(message);
    begin = &message[0];
    end = &message[n-1];

    while (begin < &message[n-1])
    {
        if(*begin != *end)
            return 0;
        begin++;
        end--;
    }
    return 1;
}