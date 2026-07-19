#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/header.h"
#include "../include/heap.h"


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

    return 0;
}
