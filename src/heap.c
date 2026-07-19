#include <stdlib.h>
#include <string.h>
#include "../include/header.h"
#include "../include/heap.h"

//allocates the memory needed for the heap and returns it
Heap *createHeap(int limit){
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->size = 0;
    heap->limit = limit;
    heap->arr = (int *)malloc(limit * sizeof(int));

    return heap;
}

//swaps values of the given parameters
void swap(int *a, int *b){
    int temp = *a;
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

//creates a max heap given an already exisiting heap/array
void buildHeap(Heap *heap){
    int size = heap->size;
    for (int i = (size - 1) / 2; i >= 0; i--){
        heapify(heap, i);
    }
}

//increas value at given index i
void increaseKey(Heap *heap, int i, int newValue){
    heap->arr[i] = newValue;
    while (i != 0 && heap->arr[(i - 1) / 2] < heap->arr[i]){
        swap(&heap->arr[i], &heap->arr[(i-1)/2]);
        i = (i - 1)/2;
    }
}

//inserts a value at the heap
void insertHeap(Heap *heap, int value){
    if(!(heap->size == heap->limit)){
        heap->size++;
        int i = heap->size - 1;
        heap->arr[i] = value;

        while(i != 0 && heap->arr[(i - 1) / 2] < heap->arr[i]){
            swap(&heap->arr[i], &heap->arr[(i - 1)/2]);
        }
    }
}

//gets max value of the heap
int getRoot(Heap *heap){
    int value = 0;
    if (heap-> size == 1){
        heap->size--;
        value = heap->arr[0];
    } else {
        value = heap->arr[0];
        heap->arr[0] = heap->arr[heap->size - 1];
        heap->size--;
        heapify(heap, 0);
    }
    return value;
}

//deletes an element at given index
void deleteKey(Heap *heap, int i){
    if(i == heap->size-1){
        heap->size--;
    } else {
        heap->arr[i] = heap->arr[heap->size-1];
        heap->size--;
        heapify(heap, i);
    }
}
