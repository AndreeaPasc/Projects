#include <stdio.h>

void pb(int n)
{
    if(n!=0)
    {
        pb(n/2);
        putchar('0'+n%2);
    }
}

int main() {
    int n;
    printf("n=");
    scanf("%d", &n);
    pb(n);
    return 0;
}