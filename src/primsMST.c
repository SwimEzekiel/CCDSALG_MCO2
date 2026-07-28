#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "heapedge.c"
#include "../include/graph.h"

Edge* pairToEdge(Pair *p, Vertex *v){
    Edge *new = malloc(sizeof(Edge));
    new->src = v->name;
    new->dst = p->name;
    new->weight = p->weight;
    new->next = p->next;

    return new;
}

void MST(Graph *g){
    Graph *tree = createGraph();
    Vertex *curV = g->adjList;
    Edge *curE = pairToEdge(curV->adj, curV);
    HeapEdge *heap = createHeapEdge(g->vertNum-1);
    int edgeNum = 0, find;

    
    do {
        curE = pairToEdge(curV->adj, curV);

        while (curE != NULL){
            if (findVertex(tree, curE->dst) == -1){
                find = findHeapEdge(heap, *curE);
                if (find > 0 && heap->arr[find].weight > curE->weight) increaseKey();
                else insertHeapEdge(heap, *curE);
            }
        }
    } while (edgeNum != tree->vertNum - 1 && curV != NULL);

    /* PSEUDOCODE FOR PRIMS
    Do while graph does not have |V|-1 elements
        Insert neighbor vertices to graph: addVertex()
            If vertex already exists
                If new weight is less than in heap, edit key
            Else, insert to heap
        Extract minimum pair and add to graph [1]: addEdge(extractMin());
        Visit vertex
    
    HEAP SPECS:
        1. Should handle a new data struct called Edge (me na bahala)
        2. Heapify should base off of weight. If may tie, destination vertex names.
        3. Extract minimum should return the Edge for pseudocode [1]
    */
    
    printGraph(tree);
    destroyGraph(tree);
}