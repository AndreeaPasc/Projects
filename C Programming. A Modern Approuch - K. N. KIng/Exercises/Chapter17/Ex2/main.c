#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *duplicate(char *str);

int main() {
    char *str1 = "Here's a string.";
    char *str2 = duplicate(str1);

    printf("Duplicate: %s", str2);

    return 0;
}

void *duplicate(char *str)
{
    char *copy = malloc(sizeof(str) + 1);
    strcpy(copy, str);
    return copy;
}
