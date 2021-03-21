/// Fibonacci

#include <stdio.h>
#include <stdlib.h>

unsigned long long int fibonacci(unsigned int n);

int main()
{
    unsigned int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("The n-th Fibonacci number is: %d", fibonacci(n));
    return 0;
}

unsigned long long int fibonacci(unsigned int n)
{
    int f0 = 0, f1 = 1, fn, i;
    for(i = 2; i < n; i++)
    {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }

    return f1;
}
