#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_LEN 20

/*
/// a)

void capitalize(char str[], int n);

int main() {
    char str[STR_LEN+1];
    printf("Enter a string: ");
    gets(str);

    capitalize(str, STR_LEN);

    printf("The upper cased string is: %s", str);
    return 0;
}

void capitalize(char str[], int n)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(isalpha(str[i]))
            str[i] = toupper(str[i]);
    }
}*/

/// b)

void capitalize(char str[], int n);

int main()
{
    char str[STR_LEN];
    printf("Enter a string: ");
    gets(str);

    capitalize(str, STR_LEN);

    printf("The upper cased string is: %s", str);
    return 0;
}

void capitalize(char str[], int n)
{
    char *s = str;
    for(*s; *s!=0; *s++)
    {
        if(isalpha(*s))
            *s = toupper(*s);
    }
}