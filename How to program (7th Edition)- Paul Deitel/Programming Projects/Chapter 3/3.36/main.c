/// How fast is your computer?

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 1;
    while(count <= 1000000000){
        if(count % 100000000 == 0)
            printf("%d\n", count);
        count++;
    }
    return 0;
}
