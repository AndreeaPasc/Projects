#include <stdio.h>

struct pinball_machine {
    char name[41];
    int year;
    enum { EM, SS } type;
    int players;
};

int main() {
    printf("Hello, World!\n");
    return 0;
}