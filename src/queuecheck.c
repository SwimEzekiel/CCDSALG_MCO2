#include <stdlib.h>
#include <string.h>
#include "../include/header.h"
#include "../include/queue.h"

/*
    Returns the size of the queue
    Parameter:
    Queue *queue - pointer to a queue
*/
int size(Queue *queue){
    return queue->size;
}

/*
    Returns 1 if queue is empty, 0 if not by checking the queue size.
    Parameter:
    Queue *queue - pointer to a queue
*/
int isQueueEmpty(Queue *queue){
    return queue->size == 0 ? 1 : 0;
}

/*
    "Peeks" for the value of the head
    Parameter:
    Queue *queue - returns the value of the head without
                   removing the value itself unlike in dequeue()
*/
int peekQueue(Queue *queue, int *status){
    int value = 0;
    if (isQueueEmpty(queue)){
        *status = 0; //cannot peak at queue if it's empty
    } else {
        *status = 1;
        value = queue->head->value;
    }

    return value;
}
