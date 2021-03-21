#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

void evaluate_expression(void);

int main(void)
{
    for (;;)
    {
        printf("\nEnter an expression: ");
        evaluate_expression();
        printf("Value of expression: %d", pop());
    }
    return 0;
}

void evaluate_expression(void)
{
    char input;
    int operandA, operandB, to_push;

    for (;;)
    {
        scanf(" %c", &input);
        switch(input)
        {
            case '+': case '-': case '*': case '/':
                operandB = pop();
                operandA = pop();
        }
        if (input >= '0' && input <= '9')
            to_push = input - '0';
        else if (input == '+')
            to_push = operandA + operandB;
        else if (input == '-')
            to_push = operandA - operandB;
        else if (input == '*')
            to_push = operandA * operandB;
        else if (input == '/')
            to_push = operandA / operandB;
        else if (input == '=')
            break;
        else
        {
            printf("\n");
            exit(EXIT_SUCCESS);
        }
        if (push(to_push) == false)
        {
            stack_overflow();
        }
    }
}