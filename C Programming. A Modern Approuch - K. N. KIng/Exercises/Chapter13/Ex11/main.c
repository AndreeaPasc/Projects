#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_LEN 20

int strcmp_function(char *s, char *t);

int main() {
    char s[STR_LEN], t[STR_LEN];
    printf("Enter the first string: ");
    gets(s);

    printf("Enter the second string: ");
    gets(t);

    int result = strcmp_function(s,t);

    printf("The result is: %d", result);

    return 0;
}

int strcmp_function(char *s, char *t)
{
    char *p1 = s;
    char *p2 = t;

    for(*p1, *p2; *p1 == *p2; *p1++, *p2++)
        if(*p1 == '\0')
            return 0;
    return *p1 - *p2;
}