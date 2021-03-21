//
// Created by andre on 22.05.2019.
//

#ifndef A_STACK_H
#define A_STACK_H

#include <stdio.h>
#include <stdbool.h>

typedef int Item;
typedef struct stack_type *Stack;

static void terminate(const char* message);
Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);

#endif //A_STACK_H
