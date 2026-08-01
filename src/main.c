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
void flush(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF); // Flush input buffer :>
}


int main(){
    Graph *graph = createGraph();
    int command = 0, weight, err;
    string input1 = "", input2 = "";

    do {
        scanf(" %d", &command);

        switch (command){
            case 1:
                scanf(" %256s", input1);
                addVertex(graph, input1);
                break;
            case 2:
                scanf(" %256s %256s %d", input1, input2, &weight);
                err = addEdge(graph, input1, input2, weight);
                if (err == 1) printf("Weight must be 1-100 only.\n");
                else if (err == 2) printf("Source vertex does not exist in graph.\n");
                else if (err == 3) printf("Dest. vertex does not exist in graph.\n");
                break;
            case 3:
                scanf(" %256s", input1);
                printf("getDegree(%s)\n", input1);
                break;
            case 4:
                scanf(" %256s %256s", input1, input2);
                printf("checkEdge(%s, %s)\n", input1, input2);
                break;
            case 5:
                scanf(" %256s", input1);
                printf("BFS(%s)\n", input1);
                break;
            case 6:
                scanf(" %256s", input1);
                printf("DFS(%s)\n", input1);
                break;
            case 7:
                scanf(" %256s %256s", input1, input2);
                printf("checkPath(%s, %s)\n", input1, input2);
                break;
            case 8:
                printf("MST()\n");
                break;
            case 9: // OPTIONAL ONLY!!
                scanf(" %256s %256s", input1, input2);
                printf("shortestPath(%s, %s)", input1, input2);
                break;
            case 10: printGraph(graph); break;
            case 11: break;
            default: 
                printf("Invalid command entered.\n"); 
                flush();
                break;
        }

        printf("\n");
    } while (command != 11);
}