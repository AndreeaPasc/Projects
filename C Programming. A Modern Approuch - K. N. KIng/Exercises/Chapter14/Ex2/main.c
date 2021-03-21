#include <stdio.h>
#include <string.h>

#define NELEMS(a) (sizeof(a)/sizeof(a[0]))


int main() {
    int array[] = {3,4};
    printf("%d", NELEMS(array));
    return 0;
}