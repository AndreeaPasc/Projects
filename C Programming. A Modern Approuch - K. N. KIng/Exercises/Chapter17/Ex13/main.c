#include <stdio.h>

struct node{
    int value;
    struct node *next;
};

struct node *insert_into_ordered_list(struct node *list,
                                      struct node *new_node)
{
    struct node *cur = list, *prev = NULL;
    while (cur != NULL && cur->value <= new_node->value) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = new_node;
    new_node->next = cur;
    return list;
}

int main(void)
{
    struct node p6    = {20, NULL};
    struct node p5    = {18, &p6};
    struct node p4    = {15, &p5};
    struct node p3    = {10, &p4};
    struct node p2    = {8,  &p3};
    struct node p1    = {5,  &p2};
    struct node new_one = {50,  NULL};
    struct node *p, *begin = &p1;

    /* print node list */
    printf("\n");
    for (p = begin; p != NULL; p = p->next)
        printf("%d%s", p->value, p->next != NULL ? ", " : "");
    printf("\n");

    /* insert new item into list */
    begin = insert_into_ordered_list(begin, &new_one);

    /* print node list again */
    for (p = begin; p != NULL; p = p->next)
        printf("%d%s", p->value, p->next != NULL ? ", " : "");
    printf("\n\n");

    return 0;
}