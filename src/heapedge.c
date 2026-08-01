#include <stdlib.h>
#include <string.h>
#include "../include/header.h"
#include "../include/heap.h"
#include "../include/heapedge.h"

/*
 * Creates a heap edge that takes in Edge values and allocates memory for it
 *
 * @param limit - size limit of the heapedge
 */
HeapEdge *createHeapEdge(int limit){
    HeapEdge *heap = (HeapEdge *)malloc(sizeof(HeapEdge));
    heap->size = 0;
    heap->limit = limit;
    heap->arr = (Edge *)malloc(limit * sizeof(Edge));

    return heap;
}

/*
 * Finds the heapedge by searching through the heap linearly
 *
 * @param *heap - pointer to the heapedge
 * @param e - edge to be found
 *
 * returns index if found, else returns -1
 */
int findHeapEdge(HeapEdge *heap, Edge e){
    for (int i = 0; i < heap->size; i++){
        if (heap->arr[i].weight == e.weight &&
            !strcmp(heap->arr[i].src->name, e.src->name) &&
            !strcmp(heap->arr[i].dst->name, e.dst->name)) return i;
    }
    return -1;
}

/*
 * Swaps the location of the given edges
 *
 * @param *a - pointer to edge a
 * @param *b - pointer to edge b
 */
void swapEdge(Edge *a, Edge *b){
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Helper function used in other heapedge functions, uses Min heap properties to swap values
 *
 * @param *heap - pointer to the heapedge
 * @param i - index given to swap at
 */
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

/*
 * Heapifies by comparing the weight of the edges
 * if same weight, compares weight, or ascii value of the destination of each edge
 *
 * @param *heap - pointer to the heapedge
 * @param i - index to heapify at
 */
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

/*
 * Builds a min heapedge given a heap
 *
 * @param *heap - pointer to the heap
 */
void buildHeapEdge(HeapEdge *heap){
    int size = heap->size;
    for (int i = (size - 1) / 2; i >= 0; i--){
        heapifyMinEdge(heap, i);
    }
}

/*
 * Insert an edge to a heapedge, still follows minheap properties
 *
 * @param *heap - pointer to the heap
 * @param value - edge to be inserted
 */
void insertHeapEdge(HeapEdge *heap, Edge value){
    if(heap->size != heap->limit){
        heap->size++;
        int i = heap->size - 1;
        heap->arr[i] = value;

        continuousSwapEdge(heap, i);
    }
}

<<<<<<< HEAD
/*
 * Gets the root edge then removes it
 *
 * @param *heap - pointer to the heap
 *
 * returns the root edge
 */
Edge getRootHeapEdge(HeapEdge *heap){
    Edge value;
=======
Edge* getRootHeapEdge(HeapEdge *heap){
    Edge* value;
>>>>>>> b479612da5211520eb4e66e325680a3f7109c0bd
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

/*
 * Deletes the edge at a given index
 *
 * @param *heap - pointer to the heap
 * @param i - index given
 */
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

/*
 * Edits an edge in the heap, then continuously swaps until it's a min heapedge again
 *
 * @param *heap - pointer to the heap
 * @param i - index of edge to edit
 * @param newValue - new value of edge
 * @param newSrc - new string value of the source of the edge
 */
void editEdge(HeapEdge *heap, int i, int newValue, string newSrc){
    heap->arr[i].weight = newValue;
    strcpy(heap->arr[i].src->name, newSrc);
    continuousSwapEdge(heap, i);
}

/*
 * Linearly searches for the destination
 *
 * @param *heap - pointer to the heap
 * @param dst - destination to be searched
 *
 * returns index if found, else returns -1
 */
int searchDest(HeapEdge *h, string dst){
    for (int i = 0; i < h->size; i++){
        if (!strcmp(h->arr[i].dst->name, dst)) return i;
    }
    return -1;
}
