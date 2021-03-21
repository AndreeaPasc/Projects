#include <stdio.h>

int check(int x, int y, int n)
{
    if((0<=x && n-1 >=x) && (0<=y && n-1 >= y))
        return 1;
    else
        return 0;
}

int main() {
    int x, y, n;
    printf("Enter x, y and n: ");
    scanf("%d %d %d", &x, &y, &n);
    check(x, y, n);
    return 0;
}

