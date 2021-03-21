//
// Created by andre on 07.05.2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100
int contents[STACK_SIZE];
int top = 0;

void stack_overflow(void)
{
    printf("Expression is too complex.\n\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
    printf("Not enough operands in expression.\n\n");
    exit(EXIT_FAILURE);
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

void evaluate_expression(void) {
    char input;
    int operandA, operandB;

    for (;;) {
        scanf(" %c", &input);
        switch (input) {
            case '+':
            case '-':
            case '*':
            case '/':
                operandA = pop();
                operandB = pop();
        }
        if (input >= '0' && input <= '9')
            push(input - '0');
        else if (input == '+')
            push(operandA + operandB);
        else if (input == '-')
            push(operandA - operandB);
        else if (input == '*')
            push(operandA * operandB);
        else if (input == '/')
            push(operandA / operandB);
        else if (input == '=')
            break;
        else {
            printf("\n");
            exit(EXIT_SUCCESS);
        }
    }
    if (top > 1) {
        printf("Too many operands in expression.\n\n");
        exit(EXIT_FAILURE);
    }
}