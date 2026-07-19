#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/header.h"
#include "../include/heap.h"
#include "../include/queue.h"
#include "../include/stack.h"


void printHeap(Heap *heap)
{
    for (int i = 0; i < heap->size; ++i)
        printf("%d ", heap->arr[i]);
    printf("\n");
}

int main(){
    Heap *heap = createHeap(10);

    insertHeap(heap, 56);
    insertHeap(heap, 120432);
    insertHeap(heap, 1435);
    insertHeap(heap, 913);
    insertHeap(heap, 2043);
    insertHeap(heap, 23434235);

    heapify(heap, 0);
    printHeap(heap);

    free(heap->arr);
    free(heap);

    Queue *queue = createQueue(6);
    enqueue(queue, 534);
    enqueue(queue, 65);
    enqueue(queue, 534354);
    enqueue(queue, 5345534);
    enqueue(queue, 534687876);

    Stack *stack = createStack(32);
    push(stack, 34);
    push(stack, 43523);
    push(stack, 30987654);

    return 0;
}
