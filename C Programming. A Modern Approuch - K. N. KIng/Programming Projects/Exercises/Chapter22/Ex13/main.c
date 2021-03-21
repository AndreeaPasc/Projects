#include <stdio.h>

int line_length(const char *filename, int n)
{
    FILE *fp;
    char ch;
    int len = 0;

    if ((fp = fopen(filename, "r")) == NULL)
        return 0;
    for (; n > 1; --n)
        while ((ch = fgetc(fp)) != '\n')
            if (ch == EOF)
                return 0;
    while ((ch = fgetc(fp)) != '\n' && ch != EOF)
        len++;
    return len;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}