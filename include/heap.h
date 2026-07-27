#include "graph.h"

typedef struct EdgeTag Edge;
typedef struct {
    Vertex *src;
    Vertex *dst;
    int weight;
    Edge *next;
} Edge;

typedef struct Heap{
    int *arr;
    char type; // kung int or char, HeapArray is a struct na nasa header.h
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
