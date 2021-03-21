#include <stdio.h>

int power(int x, int n)
{
    if(n==0)
        return 1;
    else///return x*power(x, n-1);
    {
        if(n%2==0)
            return power(x, n/2) * power(x, n/2);
        else
            return x*power(x, n-1);
    }
}


int main() {
    int x, n;
    printf("Enter a number and its power: ");
    scanf("%d %d", &x, &n);

    printf("%d^%d = %d", x, n, power(x,n));
    return 0;
}