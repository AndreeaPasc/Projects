#include <stdio.h>
#include <stdlib.h>

char *my_fgets(char *str, int n, FILE *stream)
{
    char ch, *orig = str;
    int i;

    if ((ch = fgetc(stream)) == EOF)
        return NULL;
    *str++ = ch;

    for (i = 1; i < n; ++i) {
        if ((ch = fgetc(stream)) == EOF)
            break;
        *str++ = ch;
    }

    return orig;
}

int my_fputs(const char *str, FILE *stream)
{
    while (*str != '\0')
        if (fputc(*str++, stream) == EOF)
            return EOF;
    return 0;
}
int main() {
    printf("Hello, World!\n");
    return 0;
}