#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 0;
    while(count != 1){
        printf("%d ", count);
        count = 2 + count;
    }
    return 0;
}
