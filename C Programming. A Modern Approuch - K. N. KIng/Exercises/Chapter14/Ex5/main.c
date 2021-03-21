#include <stdio.h>
#include <string.h>

#define TOUPPER(c) ('a'<=(c) && (c)<='z' ? (c)-'a'+'A':(c))

int main() {
    int i;
    char s[10];

    /// a)
    strcpy(s, "abcd");
    i=0;
    putchar(TOUPPER(s[++i]));

    printf("\n");

    /// b)
    strcpy(s, "0123");
    i=0;
    putchar(TOUPPER(s[++i]));
    return 0;
}