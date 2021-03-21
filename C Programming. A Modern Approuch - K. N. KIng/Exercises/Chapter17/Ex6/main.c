#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int value;
    struct node *next;
};

struct node *delete_from_list(struct node **list, int n)
{
    struct node *entry = *list;
    while(entry)
    {
        if(entry->value == n)
        {
            *list = entry->next;
            free(entry);
            break;
        }
        list  = &entry->next;
        entry = entry->next;
    }
}