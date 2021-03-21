#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;

    if((c = getchar()) != EOF){
        main();
        printf("%c", c);
    }
}
