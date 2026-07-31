#include <stdlib.h>
#include <string.h>
#include "../include/header.h"
#include "../include/heap.h"
#include "../include/heapedge.h"

HeapEdge *createHeapEdge(int limit){
    HeapEdge *heap = (HeapEdge *)malloc(sizeof(HeapEdge));
    heap->size = 0;
    heap->limit = limit;
    heap->arr = (Edge *)malloc(limit * sizeof(Edge));

    return heap;
}

int findHeapEdge(HeapEdge *heap, Edge e){
    for (int i = 0; i < heap->size; i++){
        if (heap->arr[i].weight == e.weight &&
            !strcmp(heap->arr[i].src->name, e.src->name) &&
            !strcmp(heap->arr[i].dst->name, e.dst->name)) return i;
    }
    return -1;
}

void swapEdge(Edge *a, Edge *b){
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

void continuousSwapEdge(HeapEdge *heap, int i){
    while(i != 0 && heap->arr[(i - 1) / 2].weight >= heap->arr[i].weight){
        if (heap->arr[(i - 1) / 2].weight == heap->arr[i].weight){
            if (strcmp(heap->arr[(i - 1) / 2].dst->name, heap->arr[i].dst->name) > 0){
                swapEdge(&heap->arr[i], &heap->arr[(i - 1)/2]);
                i = (i - 1) / 2;
            }
        } else {
            swapEdge(&heap->arr[i], &heap->arr[(i - 1)/2]);
            i = (i - 1) / 2;
        }
    }
}

//assumes na weights can't be the same, will implement na if same, compares destination
void heapifyMinEdge(HeapEdge *heap, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left].weight <= heap->arr[smallest].weight){
        if (heap->arr[left].weight == heap->arr[smallest].weight){
            if (strcmp(heap->arr[left].dst->name, heap->arr[smallest].dst->name) < 0)
                smallest = left;
        }
        else {
            smallest = left;
        }
    }

    if (right < heap->size && heap->arr[right].weight <= heap->arr[smallest].weight){
        if (heap->arr[right].weight == heap->arr[smallest].weight){
            if (strcmp(heap->arr[right].dst->name, heap->arr[smallest].dst->name) < 0)
                smallest = right;
        }
        else {
            smallest = right;
        }
    }

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

        continuousSwapEdge(heap, i);
        //replaced this vv with this ^^
        /*
        while(i != 0 && heap->arr[(i - 1) / 2].weight > heap->arr[i].weight){
            swapEdge(&heap->arr[i], &heap->arr[(i - 1)/2]);
            i = (i - 1) / 2;
        }
        */
    }
}

Edge* getRootHeapEdge(HeapEdge *heap){
    Edge* value;
    if (heap-> size == 1){
        heap->size--;
        value = &heap->arr[0];
    } else {
        value = &heap->arr[0];
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
            continuousSwapEdge(heap, i);
        } else
            heapifyMinEdge(heap, i);
    }
}

void editEdge(HeapEdge *heap, int i, int newValue, string newSrc){
    heap->arr[i].weight = newValue;
    strcpy(heap->arr[i].src->name, newSrc);
    continuousSwapEdge(heap, i);
}

int searchDest(HeapEdge *h, string dst){
    for (int i = 0; i < h->size; i++){
        if (!strcmp(h->arr[i].dst->name, dst)) return i;
    }
    return -1;
}
