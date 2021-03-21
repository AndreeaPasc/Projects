/// Printing the numbers 1 to 4 on the same line using printf

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /// a) using one printf statement with no conversion specifiers
    printf("1 2 3 4\n");

    /// b) using one printf statement with four coversion specifiers
    int a, b, c, d;
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    printf("%d %d %d %d\n", a, b, c, d);

    /// c) using four printf statements
    printf("1 ");
    printf("2 ");
    printf("3 ");
    printf("4");
    return 0;
}
