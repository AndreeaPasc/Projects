#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct s{
    char a;
    int b[2];
    float c;
};

int main() {

    struct s test;

    printf("The offsets are:\n");
    printf("%d\n", offsetof(struct s, a));
    printf("%d\n", offsetof(struct s, b));
    printf("%d\n", offsetof(struct s, c));

    printf("The sizes are:\n");
    printf("%d\n", sizeof(struct s));
    printf("%d\n", sizeof(test.a));
    printf("%d\n", sizeof(test.b));
    printf("%d\n", sizeof(test.c));

    if(sizeof(test.a)< offsetof(struct s,b))
        printf("There is a %d-byte hole between a and b.\n", sizeof(test.b) - sizeof(test.a));
    if(sizeof(test.b) + offsetof(struct s, b) < offsetof(struct s, c))
        printf("There is a %d-byte hole between b and c.\n", offsetof(struct s, c) - offsetof(struct s, b) -
                sizeof(test.b));
    if(sizeof(test.c) + offsetof(struct s, c) < sizeof(struct s))
        printf("There is a %d-byte hole after c.\n", sizeof(struct s) - sizeof(test.c) -
                offsetof(struct s, c));

    return 0;
}