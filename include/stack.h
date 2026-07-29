#ifndef stack_h
#define stack_h


typedef struct { //Stack itself.
    int *collection;
    int limit;
    int size;
} Stack;

//functions from modify_stack.c
Stack *createStack(int limit);
void destroyStack(Stack *stack);
int pop(Stack *stack, int item);
int push(Stack *stack, int item);

//functions from check_stack.c
int isStackFull(Stack *stack);
int isStackEmpty(Stack *stack);
int peekStack(Stack *stack);

#endif