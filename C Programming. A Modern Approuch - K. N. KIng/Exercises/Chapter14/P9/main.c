#include <stdio.h>
#include <string.h>
#include <math.h>

#define CHECK(x,y,n) (0<=(x) && (x)<=n-1) && (0<=(y) && (y)<=n-1) ? 1:0
#define MEDIAN(x,y,z) ((x) > (y) && (x) < (z) ? (x) : \
                       (y) > (x) && (y) < (z) ? (y) : \
                       (z) > (x) && (z) < (y) ? (z) : \
                       (x) < (y) && (x) > (z) ? (x) : \
                       (y) < (x) && (y) > (z) ? (y) : \
                       (z) < (x) && (z) > (y) ? (z) : (x))
#define POLYNOMIAL(x) (3*pow((x),5) + 2*pow((x),4) - 5*pow((x),3)- pow((x),2) + 7*(x) - 6)

int main() {
    float n = 10, x = 3, y = 4;
    printf("%d\n", CHECK(x,y,n));
    printf("%.2lf\n", MEDIAN(x,y,n));
    printf("%.2lf\n", POLYNOMIAL(x));
    return 0;
}