#include "graph.h"

typedef struct Edge {
    Vertex *src;
    Vertex *dst;
    int weight;
    struct Edge *next;
} Edge;

typedef struct Heap{
    int *arr;
    int size;
    int limit;
} Heap;

typedef struct HeapEdge{
    Edge *arr;
    int size;
    int limit;
} HeapEdge;

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
