typedef struct { //Stack itself.
    Value *collection;
    char type;
    int limit;
    int size;
} Stack;

//functions from modify_stack.c
Stack *createStack(int limit);
void destroyStack(Stack *stack);
int pop(Stack *stack, void *item, char dataType);
int push(Stack *stack, void *item, char dataType);

//functions from check_stack.c
int isStackFull(Stack *stack);
int isStackEmpty(Stack *stack);
int peekStack(Stack *stack, void *item, char dataType);
