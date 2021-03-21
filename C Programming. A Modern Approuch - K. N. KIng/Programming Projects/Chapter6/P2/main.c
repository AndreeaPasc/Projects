#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, reminder;
    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);


   while(n>0)
    {
        reminder = m % n;
        m = n;
        n = reminder;
    }

    printf("The greatest common divisor is: %d", m);
    return 0;
}
