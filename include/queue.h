typedef struct Node {
    Value value; //Keeps a value struct
    char type;   //determines what value to be used in the struct
    struct Node *next;  //Pointer to the next node
} Node;

typedef struct { //The queue itself
    Node *head; //the head, which is the first element of the queue, first one to come in
    Node *tail; //the tail, which is the last element or last one to come in
    int size;
} Queue;

//functions inside queue_modify.c
Queue *createQueue();
void enqueue(Queue *queue, void* value, char dataType);
Value dequeue(Queue *queue);

//functions inside queue_check.c
int size(Queue *queue);
int isQueueEmpty(Queue *queue);
Value peekQueue(Queue *queue, int *status);
void destroyQueue(Queue *queue);

//functions for conversion and evaluation
void convertToPostfix(string equation, Queue *main);
int evaluatePostfix(Queue *postfix, int *error);
