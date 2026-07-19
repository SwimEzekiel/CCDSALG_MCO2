#include <stdlib.h>
#include <string.h>
#include "../include/header.h"
#include "../include/stack.h"

/*
    Creates a stack based on a given limit
    Paramater:
    int limit - used to determine the max size of the stack
*/
Stack *createStack(int limit){
    Stack *stack = malloc(sizeof(Stack));

    stack->collection = malloc(sizeof(int) * limit); //creates initual size for the stack

    stack->limit = limit;
    stack->size = 0;

    return stack;
}

/*
    Frees the stack from memory
    Parameter:
    Stack *stack - pointer to a stack
*/
void destroyStack(Stack *stack){
    free(stack->collection);
    free(stack);
}

/*
    Removes the highest layer from the stack. Returns 1 if successful, 0 if stack was initially empty
    Parameters:
    Stack *stack - pointer to a stack
    int item - item to be popped
*/
int pop(Stack *stack, int item){
    if (isStackEmpty(stack))
        return 0;

    stack->size--;
    int value = stack->collection[stack->size];
    return value;
}

/*
    Pushes an item to the top, returns 1 if successful, 0 if it were already full
    Parameters:
    Stack *stack - pointer to a stack
    int item - item to be pushed
*/
int push(Stack *stack, int item){
    if (isStackFull(stack))
        return 0;

    stack->collection[stack->size] = item;
    stack->size++;

    return 1;
}
