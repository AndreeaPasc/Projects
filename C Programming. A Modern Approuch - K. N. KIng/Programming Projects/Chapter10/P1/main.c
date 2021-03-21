#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void stack_overflow(void)
{
    printf("Stack overflow");
}

void stack_underflow(void)
{
    printf("Stack underflow. The parentheses are not matched.");
}

void make_empty(void)
{
    top=0;
}

bool is_empty(void)
{
    return top==0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(char i)
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
    char braces;
    int i;
    printf("Enter parentheses and/or braces: ");
    scanf(" %c", &braces);

    bool is_nested = true;

    while(braces!='\n')
    {
        if(braces == '(' || braces == '{')
            push(braces);
        if(braces == ')' && pop() != '(')
            is_nested = false;
        if(braces == '}' && pop() != '{')
            is_nested = false;

        braces = getchar();
    }

    if(is_empty() == false)
        is_nested = false;

    if(is_nested)
        printf("Parentheses/braces are nested properly\n\n");
    else
        printf("Parentheses/braces are not nested properly\n\n");
    return 0;
}