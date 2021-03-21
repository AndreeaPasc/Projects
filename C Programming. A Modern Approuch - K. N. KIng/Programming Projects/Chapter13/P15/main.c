#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define LEN 50
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

int evaluate_RPN_expression(const char *expression)
{
    char *digit = expression;
    int operandA, operandB;

    for(; *digit != '\n'; digit++)
    {
        switch (*digit)
        {
            case '+': case '-': case '*': case '/':
                operandA = pop();
                operandB = pop();
        }
        if(*digit>='0' && *digit<= '9')
            push(*digit - '0');
        else if (*digit == '+')
            push(operandA + operandB);
        else if (*digit == '-')
            push(operandA - operandB);
        else if (*digit == '*')
            push(operandA * operandB);
        else if (*digit == '/')
            push(operandA / operandB);
        else if (*digit == '=')
            break;
        else
        {
            printf("\n");
            exit(EXIT_SUCCESS);
        }
    }
    if(top>1)
    {
        printf("Too many operands in expression.\n\n");
        exit(EXIT_FAILURE);
    }
}
int main() {

    char input, expression[LEN];
    int i;
    for(;;)
    {
        printf("\nEvaluate an expression: ");
        for(i=0; (input = getchar()) != '\n'; i++)
        {
            if(i<LEN)
                expression[i] = input;
        }
        expression[i+1] = '\0';
        printf("Value of expression: %d", evaluate_RPN_expression(expression));
    }
    return 0;
}