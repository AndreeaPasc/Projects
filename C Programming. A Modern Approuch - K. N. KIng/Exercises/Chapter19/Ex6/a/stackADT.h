//
// Created by andre on 22.05.2019.
//

#ifndef A_STACKADT_H
#define A_STACKADT_H

#include <stdbool.h> /* C99 only */

typedef int Item;

typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void (push(Stack s, Item i));
Item pop(Stack s);
Item peek(Stack s);

#endif //A_STACKADT_H
