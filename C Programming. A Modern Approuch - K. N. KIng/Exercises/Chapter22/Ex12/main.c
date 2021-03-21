#include <stdio.h>

int count_periods(const char *filename)
{
    FILE *fp;
    int n = 0;
    char ch;

    if ((fp = fopen(filename, "r")) != NULL) {
        while ((ch = fgetc(fp)) != EOF)
            if (ch == '.')
                n++;
        fclose(fp);
    }

    return n;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}