#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/header.h"
#include "../include/heap.h"
#include "../include/queue.h"
#include "../include/stack.h"
#include "../include/graph.h"

void printVertices(Graph *g){
    Vertex *cur = g->adjList;
    while (cur != NULL){
        printf(cur->name);
        if (cur->nextVert != NULL) printf(", ");
        cur = cur->nextVert;
    }
    printf("}\n");
}
void printEdges(Graph *g){
    Vertex *curV = g->adjList;
    Pair   *curP = NULL;

    if (curV != NULL && curV->adj != NULL) curP = curV->adj;

    while (curV != NULL){
        curP = curV->adj;
        while (curP != NULL){
            printf("     (%s, %s, %d)\n", curV->name, curP->name, curP->weight);
            curP = curP->next;
        }
        curV = curV->nextVert;
    }
    printf("}\n");
}
void printGraph(Graph *g){
    printf("G = (V,E)\n");
    printf("V = {");
    printVertices(g);
    printf("E = {");
    printEdges(g);
}


int main(){
    Graph *graph = createGraph();
    printGraph(graph);
    addVertex(graph, "Fonsi");
    addVertex(graph, "Zik");
    printGraph(graph);
    addEdge(graph, "Fonsi", "Zik", 67);
    printGraph(graph);
    addVertex(graph, "Matthew");
    addVertex(graph, "John Toby Agsangre Pickavant");
    addEdge(graph, "Matthew", "John Toby Agsangre Pickavant", 69);
    addEdge(graph, "Matthew", "Fonsi", 1);
    printGraph(graph);
}