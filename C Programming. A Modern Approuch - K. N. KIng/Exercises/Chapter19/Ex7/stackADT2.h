//
// Created by andre on 22.05.2019.
//

#ifndef EX7_STACKADT2_H
#define EX7_STACKADT2_H

#include <stdbool.h> /* C99 only */

typedef int Item;

typedef struct stack_type *Stack;

Stack create(int size);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void (push(Stack s, Item i));
Item pop(Stack s);

#endif //EX7_STACKADT2_H
