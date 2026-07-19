#include <stdlib.h>
#include <string.h>
#include "../include/header.h"
#include "../include/queue.h"

/*
    Allocates memory to create a queue, returns the pointer to a queue
*/
Queue *createQueue(){
    Queue *queue = malloc(sizeof(Queue));

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

/*
    Puts a value inside a queue, returns void
    Parameters:
    Queue *queue - pointer to a queue
    int value - value to be put in the queue
*/
void enqueue(Queue *queue, int value){
    Node *newnode = malloc(sizeof(Node)); //allocates memory for the new node

    newnode->value = value;
    newnode->next = NULL;

    if (isQueueEmpty(queue)){ //since there'll be only one value, that value is both the head and tail
        queue->head = newnode;
        queue->tail = newnode;
    } else {
        queue->tail->next = newnode;
        queue->tail = newnode;
    }

    queue->size++;
}

/*
    Removes the head of the queue and returns the value itself
    Parameter:
    Queue *queue - pointer to a queue
*/
int dequeue(Queue *queue){
    int result = queue->head->value;

    Node *oldhead = queue->head;

    if (queue->size == 1){ //assigns both head and tail as null since the one
        queue->head = NULL; //and only value was removed
        queue->tail = NULL;
    } else
        queue->head = queue->head->next;

    free(oldhead); //frees the queue from memory
    queue->size--;

    return result;
}
/*
    Deletes the queue from memory, returns void
    Parameter:
    Queue *queue - pointer to a queue
*/
void destroyQueue(Queue *queue){
    Node *currentnode = queue->head;

    while(currentnode != NULL){ //loops through all values and frees them one by one
        Node *temp = currentnode;
        currentnode = currentnode->next;
        free(temp);
    }

    free(queue); //frees the parameter
}
