#include <stdio.h>
#include <stdlib.h>

unsigned int mystery(unsigned int a, unsigned int b);

int main()
{
    unsigned int x, y;

    printf("%s", "Enter two positive integers: ");
    scanf("%u%u", &x, &y);

    printf("The result is: %u\n", mystery(x, y));
    return 0;
}

unsigned int mystery(unsigned int a, unsigned int b){
    if(1 == b){
        return a;
    }
    else
    {
        return a + mystery(a, b - 1);
    }
}
