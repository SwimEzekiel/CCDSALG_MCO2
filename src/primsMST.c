#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/heapedge.h"

Edge* pairToEdge(Pair *p, Vertex *v){
    Edge *new = malloc(sizeof(Edge));
    new->src = malloc(sizeof(Vertex));
    new->dst = malloc(sizeof(Vertex));
    strcpy(new->src->name, v->name);
    strcpy(new->dst->name, p->name);
    new->weight = p->weight;
    new->next = NULL;

    return new;
}

void MST(Graph *g){
    Graph *tree = createGraph();
    Vertex *curV = g->adjList;
    Pair *curP;
    Edge *curE;
    HeapEdge *heap = createHeapEdge(g->vertNum-1);
    int edgeNum = 0, find;
    string visit;

    do
    {
        // Base case(?)
        if (curV != NULL) curP = curV->adj;
        else curP = NULL;

        // Add neighbors phase
        while (curP != NULL){
            curE = pairToEdge(curP, curV);
            if (findVertex(g, curE->dst->name) > -1) continue; 
            else if ((find = searchDest(heap, curE->dst->name)) > -1) editEdge(heap, find, curE->weight, curE->src->name);
            else insertHeapEdge(heap, *curE);

            curP = curP->next;
        }

        // Visit next unvisited node with least weight
        *curE = getRootHeapEdge(heap);
        curV = getVertexByName(g, curE->dst->name);
        insertHeapEdge(heap, *curE);
        addVertex(tree, curV->name);
        addEdge(tree, tree->vertNum, curV->name, curE->weight);
        deleteKeyEdge(heap, 0);
    } while (heap->size != 0);
    
    
    printGraph(tree);
    destroyGraph(tree);
}