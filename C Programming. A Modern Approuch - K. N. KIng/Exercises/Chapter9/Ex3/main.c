#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n)
{
    int reminder;
    while(n>0)
    {
        reminder = m%n;
        m=n;
        n=reminder;
    }

    return printf("The greatest common divisor is: %d", m);
}

int main()
{
    int n,  m;

    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);
    gcd(m, n);

    return 0;
}
