#include <stdio.h>

#define xstr(s) str(s)
#define str(s) #s
#define LINE_FILE "Line " xstr(__LINE__) " of file " __FILE__

int main(void)
{
    const char *str = LINE_FILE;

    printf("\n%s\n\n", str);
    return 0;
}