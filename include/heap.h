typedef struct Heap{
    HeapArray *arr;
    char type; // kung int or char, HeapArray is a struct na nasa header.h
    int size;
    int limit;
} Heap;

//function prototypes
Heap *createHeap(int limit);
void swap(int *a, int *b);
void heapify(Heap *heap, int i);
void buildHeap(Heap *heap);
void increaseKey(Heap *heap, int index, int newValue);
void insertHeap(Heap *heap, int value);
int getMax(Heap *heap);
void deleteKey(Heap *heap, int index);
