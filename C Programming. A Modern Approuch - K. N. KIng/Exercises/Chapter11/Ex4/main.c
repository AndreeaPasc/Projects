#include <stdio.h>
#include <stdlib.h>

void swap(int *p, int *q);

int main() {
    int i, j;
    printf("Enter two numbers: ");
    scanf("%d %d", &i, &j);
    swap(&i, &j);
    printf("The numbers after swapping are: %d %d", i, j);
    return 0;
}

void swap(int *p, int *q)
{
    int carry;
    carry = *p;
    *p = *q;
    *q = carry;
}