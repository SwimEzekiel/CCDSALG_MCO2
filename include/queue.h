typedef struct Node {
    int value; //Keeps an int value
    struct Node *next;  //Pointer to the next node
} Node;

typedef struct { //The queue itself
    Node *head; //the head, which is the first element of the queue, first one to come in
    Node *tail; //the tail, which is the last element or last one to come in
    int size;
} Queue;

//functions inside queue_modify.c
Queue *createQueue();
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);

//functions inside queue_check.c
int size(Queue *queue);
int isQueueEmpty(Queue *queue);
int peekQueue(Queue *queue, int *status);
void destroyQueue(Queue *queue);
