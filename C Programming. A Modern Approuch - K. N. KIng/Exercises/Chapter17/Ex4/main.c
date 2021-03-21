#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point {int x,y;};
struct rectangle{struct point upper_left, lower_right;};
struct rectangle *p;

int main() {

    p = malloc(sizeof(struct rectangle));
    p->upper_left.x = 10;
    p->upper_left.y = 25;
    p->lower_right.x = 20;
    p->lower_right.y = 15;

    printf("Upper left: (%d, %d)", p->upper_left.x, p->upper_left.y);
    printf("\nLower right: (%d, %d)", p->lower_right.x, p->lower_right.y);

    return 0;
}