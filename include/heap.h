#ifndef heap_h
#define heap_h

#include "graph.h"

//Can be used to create an edge
typedef struct Edge {
typedef struct Vertex Vertex;

struct Edge {
    Vertex *src;
    Vertex *dst;
    int weight;
    struct Edge *next;
};

//a structure of a regular heap, not used for heapedge
//since it only keeps int values
typedef struct Heap{
    int *arr;
    int size;
    int limit;
} Heap;


//function prototypes from heap.c
Heap *createHeap(int limit);
void swap(int *a, int *b);
void heapify(Heap *heap, int i);
void buildHeap(Heap *heap);
void increaseKey(Heap *heap, int index, int newValue);
void insertHeap(Heap *heap, int value);
int getRoot(Heap *heap);
void deleteKey(Heap *heap, int index);
void printHeap(Heap *heap);

#endif
