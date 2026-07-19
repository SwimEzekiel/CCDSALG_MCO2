#include <stdlib.h>
#include <string.h>
#include "../include/header.h"
#include "../include/stack.h"

/*
    Checks if stack is full
    Parameter:
    Stack *stack - pointer to a stack
*/
int isStackFull(Stack *stack){
    return stack->limit == stack->size;
}

/*
    Checks if stack is empty
    Parameter:
    Stack *stack - pointer to a stack
*/
int isStackEmpty(Stack *stack){ //returns 1 if empty, 0 if not
    return stack->size == 0;
}

/*
    Checks for the value at the top of the stack, without removing it. returns the value if successful, 0 if not
    Parameter:
    Stack *stack - pointer to a stack
*/
int peekStack(Stack *stack){
    if (isStackEmpty(stack))
        return 0;

    return stack->collection[stack->size];
}
