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
    addVertex(tree, curV->name);
    Pair *curP;
    Edge *curE, *root = malloc(sizeof(Edge));
    HeapEdge *heap = createHeapEdge(g->vertNum-1);
    int edgeNum = 0, find;
    string visit;
    int debug = 0;

    do
    {
        // Base case(?)
        if (curV != NULL) curP = curV->adj;
        else curP = NULL;

        // Add neighbors phase
        while (curP != NULL){
            curE = pairToEdge(curP, curV);
            if (findVertex(tree, curE->dst->name) > -1) continue; 
            else if ((find = searchDest(heap, curE->dst->name)) > -1) editEdge(heap, find, curE->weight, curE->src->name);
            else insertHeapEdge(heap, *curE);

            curP = curP->next;
        }

        // Visit next unvisited node with least weight
        root = getRootHeapEdge(heap);
        printf("1");
        curV = getVertexByName(g, curE->dst->name);
        printf("2");
        insertHeapEdge(heap, *curE);
        printf("3");
        addVertex(tree, curV->name);
        printf("4\n");
        addEdge(tree, findVertex(tree, curE->src->name), curV->name, curE->weight);
        printGraph(tree);
        deleteKeyEdge(heap, 0);
        printf("6");
        debug++;
    } while (heap->size != 0);
    
    
    printGraph(tree);
    destroyGraph(tree);
}