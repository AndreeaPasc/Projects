#include <stdio.h>

struct part{
    int number;
    char *name;
    int on_hand;
};

void print_part(struct part *p)
{
    printf("Part number: %d", p->number);
    printf("Part name: %s", p->name);
    printf("Quantity on hand: %d", p->on_hand);
}