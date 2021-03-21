#include <stdio.h>
#include <stdlib.h>

double inner_product(const double *a, const double *b, int n);

int main() {
    int n;
    printf("Enter the size of the arrays: ");
    scanf("%d", &n);

    double a[n], b[n];
    int i;

    for(i=0; i<n; i++)
        scanf("%lf", &a[i]);

    for(i=0; i<n; i++)
        scanf("%lf", &a[i]);

    printf("%lf", inner_product(&a, &b, n));
    return 0;
}

double inner_product(const double *a, const double *b, int n)
{
    double  *pa, *pb, product;
    product = 0;

    for(pa = a, pb = b; pa<a+n-1; )
        product = (*pa+*pb) * (*pa++ + *pb++);

    return product;
}