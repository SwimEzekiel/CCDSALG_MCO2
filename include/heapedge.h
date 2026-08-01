#ifndef heapedge_h
#define heapedge_h
#include "heap.h"

typedef struct HeapEdge{
    Edge *arr;
    int size;
    int limit;
} HeapEdge;

HeapEdge* createHeapEdge(int i);
int findHeapEdge(HeapEdge*, Edge);
void swapEdge(Edge*, Edge*);
void continuousSwapEdge(HeapEdge*, int i);
void heapifyMinEdge(HeapEdge*, int i);
void buildHeapEdge(HeapEdge*);
void insertHeapEdge(HeapEdge*, Edge);
Edge* getRootHeapEdge(HeapEdge*);
void deleteKeyEdge(HeapEdge*, int i);
void editEdge(HeapEdge*, int i, int newValue, string);
int searchDest(HeapEdge*, string);

#endif