#include <stdio.h>

double inner_product(double a[], double b[], int n)
{
    int i;
    double sum=0;
    for(i=0;i<n;i++)
    {
        sum += a[i]*b[i];
    }
    return  printf("%lf", sum);
}

int main() {
    int n, i;
    printf("n= ");
    scanf("%d", &n);

    double a[n], b[n];

    for(i=0;i<n;i++)
    {
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }

    for(i=0;i<n;i++)
    {
        printf("b[%d] = ", i);
        scanf("%lf", &b[i]);
    }

    inner_product(a,b,n);
    return 0;
}