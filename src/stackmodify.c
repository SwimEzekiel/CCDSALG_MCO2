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

    stack->collection = malloc(sizeof(Value) * limit); //creates initual size for the stack

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
    void *item - item itself to pop, can accept int, char, or string
    char dataType - shows the data type of item
*/
int pop(Stack *stack, void *item, char dataType){
    if (isStackEmpty(stack))
        return 0;

    stack->size--;
    switch (dataType){
        case 'i': *(int *)item = stack->collection[stack->size].i; break;
        case 'c': *(char *)item = stack->collection[stack->size].c; break;
        case 's': strcpy((char *)item, stack->collection[stack->size].s); break;
        default: return 0; //used if characters other than these are used like 'z'
    }


    return 1;
}

/*
    Pushes an item to the top, returns 1 if successful, 0 if it were already full
    Parameters:
    Stack *stack - pointer to a stack
    void *item - item to put at the top
    char dataType - shows data type of the item in the parameter
*/
int push(Stack *stack, void *item, char dataType){
    if (isStackFull(stack))
        return 0;

    switch (dataType){
        case 'i': stack->collection[stack->size].i = *(int *)item; break;
        case 'c': stack->collection[stack->size].c = *(char *)item; break;
        case 's': strcpy(stack->collection[stack->size].s, (char *)item); break;
        default: return 0;
    }
    stack->size++;

    return 1;
}
