#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100
int contents[STACK_SIZE];
int *top_ptr;

void make_empty(void)
{
    top_ptr = &contents[0];
}

bool is_empty(void)
{
    return top_ptr == &contents[0];
}

bool is_full(void)
{
    return top+ptr == &contents[STACK_SIZE];
}

void push(int i)
{
    if(is_full())
        stack_overflow();
    else
        contents[top++] = i;
}

int pop(void)
{
    if(is_empty())
        stack_underflow();
    else
        return contents[--top];
}

int main() {

    return 0;

}