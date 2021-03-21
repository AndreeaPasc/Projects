#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, sum=0;
    printf("This program sums a series of integers.\n");
    printf("Enter integers (0 to terminate): ");

    scanf("%d", &n);
    while(n!=0)
    {
        sum += n;
        scanf("%d", &n);
    }
    printf("The sum is: %d", sum);
    return 0;
}

/*

for(i=1; i<=n;i++)
    printf("%10d%10d\n", i, i*i);

*/

/*

i=1;
odd=3;
for(square=1;i<=n;odd+=2)
{
    printf("%10d%10d\n", i, square);
    ++i;
    square += odd;
}

/*

printf("The program sums a series of integers");

scanf("%ld", &n);
while(n!=0)
{
    sum+=n;
    scanf("%ld", &n);
}

printf("The sum is: %ld", sum);
