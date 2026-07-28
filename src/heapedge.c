#include <stdlib.h>
#include <string.h>
#include "../include/header.h"
#include "../include/heap.h"

HeapEdge *createHeapEdge(int limit){
    HeapEdge *heap = (HeapEdge *)malloc(sizeof(HeapEdge));
    heap->size = 0;
    heap->limit = limit;
    heap->arr = (Edge *)malloc(limit * sizeof(Edge));

    return heap;
}

int findHeapEdge(HeapEdge *heap, Edge e){
    Edge *cur = heap->arr;
    for (int i = 0; i < heap->size; i++){
        if (cur->weight == e.weight &&
            !strcmp(cur->src, e.src) &&
            !strcmp(cur->dst, e.dst)) return i;
        else cur = cur->next;
    }

    return -1;
}

void swapEdge(Edge *a, Edge *b){
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

//assumes na weights can't be the same, will implement na if same, compares destination
void heapifyMinEdge(HeapEdge *heap, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left].weight < heap->arr[smallest].weight)
        smallest = left;

    if (right < heap->size && heap->arr[right].weight < heap->arr[smallest].weight)
        smallest = right;

    if (smallest != i){
        swapEdge(&heap->arr[i], &heap->arr[smallest]);
        heapifyMinEdge(heap, smallest);
    }
}

void buildHeapEdge(HeapEdge *heap){
    int size = heap->size;
    for (int i = (size - 1) / 2; i >= 0; i--){
        heapifyMinEdge(heap, i);
    }
}

void insertHeapEdge(HeapEdge *heap, Edge value){
    if(heap->size != heap->limit){
        heap->size++;
        int i = heap->size - 1;
        heap->arr[i] = value;

        while(i != 0 && heap->arr[(i - 1) / 2].weight > heap->arr[i].weight){
            swapEdge(&heap->arr[i], &heap->arr[(i - 1)/2]);
            i = (i - 1) / 2;
        }
    }
}

Edge getRootHeapEdge(HeapEdge *heap){
    Edge value;
    if (heap-> size == 1){
        heap->size--;
        value = heap->arr[0];
    } else {
        value = heap->arr[0];
        heap->arr[0] = heap->arr[heap->size - 1];
        heap->size--;
        heapifyMinEdge(heap, 0);
    }
    return value;
}

void deleteKeyEdge(HeapEdge *heap, int i){
    if(i == heap->size-1){
        heap->size--;
    } else {
        heap->arr[i] = heap->arr[heap->size-1];
        heap->size--;
        if(i != 0 && heap->arr[(i - 1) / 2].weight > heap->arr[i].weight){
            while(i != 0 && heap->arr[(i - 1) / 2].weight > heap->arr[i].weight){
                swapEdge(&heap->arr[i], &heap->arr[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        } else
            heapifyMinEdge(heap, i);
    }
}

void editEdge(HeapEdge *heap, int i, int newValue, string newSrc){
    heap->arr[i].weight = newValue;
    strcpy(heap->arr[i].src, newSrc);
    while (i != 0 && heap->arr[(i - 1) / 2] < heap->arr[i]){
        swap(&heap->arr[i], &heap->arr[(i-1)/2]);
        i = (i - 1)/2;
    }
}