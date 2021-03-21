#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool search(const int a[], int n, int key);

int main() {
    int n, key, *p;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d elements: ", n);
    for(p=a; p<a+n; p++) \
    {
        scanf("%d", p);
    }

    printf("Enter a key: ");
    scanf("%d", &key);

    printf("%d", search(a, n, key));

    return 0;
}

bool search(const int a[], int n, int key)
{
    int *p;
    for(p=a; p<a+n; p++)
    {
        if(*p==key)
            return true;
        else
            return false;
    }
}