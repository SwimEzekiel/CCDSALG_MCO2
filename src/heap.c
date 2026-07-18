#include <stdlib.h>
#include <string.h>
#include "../include/header.h"
#include "../include/heap.h"

//allocates the memory needed for the heap and returns it
Heap *createHeap(int limit, char type){
    Heap *heap = (Heap *)malloc(sizeof(Heap * limit));
    heap->size = 0;
    heap->limit = limit;
    heap->type = type;
    heap->arr = heap->type == 'i' ? (int *)malloc(limit * sizeof(int)) : (char *)malloc(limit * sizeof(char));

    return heap;
}

//swaps values of the given parameters
void swap(void* *a, void* *b){
    int temp *a;
    *a = *b;
    *b = temp;
}

//heapifies node at a given index
void heapify(Heap *heap, int i){
    int largest = i;
    int left = 2 * i + 2;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left] > heap->arr[largest])
            largest = left;

    if (right < heap->size && heap->arr[right] > heap->arr[largest])
            largest = right;

    if (largest != i){
        swap(&heap->arr[i], &heap->arr[largest]);
        heapify(heap, largest);
    }
}
void buildHeap(Heap *heap);
void increaseKey(Heap *heap, int index, int newValue);
void insertHeap(Heap *heap, int value);
int getMax(Heap *heap);
void deleteKey(Heap *heap, int index);
