//
// Created by andre on 22.05.2019.
//

#ifndef EX1_QUEUE_H
#define EX1_QUEUE_H

#include <stdbool.h>

typedef int Item;

void insert(Item value);
void remove();
Item get_first_item();
Item get_last_item();
bool is_empty();


#endif //EX1_QUEUE_H
