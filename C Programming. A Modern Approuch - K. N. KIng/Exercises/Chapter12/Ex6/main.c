#include <stdio.h>

int sum_array(const int a[], int n);

int main() {

    return 0;
}

int sum_array(const int a[], int n)
{
    int *p, sum = 0;
    for(p=a; p<a+n; p++)
        sum += *p;
    return sum;
}