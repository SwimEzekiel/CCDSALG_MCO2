#include <stdlib.h>
#include <string.h>
#include "../include/heap.h"

/*
 * Creates a heap by allocating the memory needed for it
 *
 * @param limit - dictates size limit of the heap
 *
 * returns the pointer to the heap
 */
Heap *createHeap(int limit){
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->size = 0;
    heap->limit = limit;
    heap->arr = (int *)malloc(limit * sizeof(int));

    return heap;
}

/*
 * Swaps values in the heap
 *
 * @param *a - pointer to the value to switch to param b's postion
 * @param *b - pointer to the value to switch to param a's position
 */
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Heapifies a heap at a given index, following the rules of a max heap
 *
 * @param *heap - pointer to a heap
 */
void heapify(Heap *heap, int i){
    int largest = i;
    int left = 2 * i + 1;
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

/*
 * Converts the heap to a max heap given it already has values
 *
 * @param *heap - pointer to a heap
 */
void buildHeap(Heap *heap){
    int size = heap->size;
    for (int i = (size - 1) / 2; i >= 0; i--){
        heapify(heap, i);
    }
}

/*
 * Inserts a value at the heap
 *
 * @param *heap - pointer to the heap
 * @param value - value to be inserted
 */
void insertHeap(Heap *heap, int value){
    if(heap->size != heap->limit){
        heap->size++;
        int i = heap->size - 1;
        heap->arr[i] = value;

        while(i != 0 && heap->arr[(i - 1) / 2] < heap->arr[i]){
            swap(&heap->arr[i], &heap->arr[(i - 1)/2]);
            i = (i - 1) / 2;
        }
    }
}

/*
 * Gets the max value of the heap, then deletes it
 *
 * @param *heap - pointer to the heap
 */
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

/*
 * Deletes a value given an index i
 *
 * @param *heap - pointer to the heap
 * @param i - index to delete
 */
void deleteKey(Heap *heap, int i){
    if(i == heap->size-1){
        heap->size--;
    } else {
        heap->arr[i] = heap->arr[heap->size-1];
        heap->size--;
        if(i != 0 && heap->arr[(i - 1) / 2] < heap->arr[i]){
            while(i != 0 && heap->arr[(i - 1) / 2] < heap->arr[i]){
                swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        } else
            heapify(heap, i);
    }
}
