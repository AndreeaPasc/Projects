#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

int main() {

    for(;;)
    {
        printf("\nEvaluate an expression: ");
        evaluate_expression();
        printf("Value of expression: %d", pop());
    }
    return 0;
}