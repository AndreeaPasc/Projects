#include <stdio.h>

int gcd(int m, int n) {
    int reminder;
    if(n==0)
        return printf("The greatest common divisor is: %d", m);
    else gcd(n, m%n);
}

int main() {

    int n, m;

    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);
    gcd(m, n);

    return 0;
    }