/// Recursive main

#include <stdio.h>
#include <stdlib.h>

int main()
{
    static int count = 1;
    count++;
    printf("%d\n", count);
    main();
    return 0;
}
