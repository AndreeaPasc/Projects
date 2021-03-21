#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STR_LEN 20

void censor(char str[], int n);

int main() {
    char str[STR_LEN+1];
    printf("Enter a string: ");
    gets(str);

    censor(str, STR_LEN);

    printf("The censored string is: %s", str);

    return 0;
}

void censor(char str[], int n)
{
    int i = 0;
    for(; str[i] != '\0'; i++)
    {
        if(str[i] == 'f' && str[i+1] == 'o' && str[i+2] == 'o')
        {
            str[i] = str[i+1] = str[i+2] = 'x';
        }
    }
}