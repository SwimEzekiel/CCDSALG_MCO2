#include <string.h>
#include <stdlib.h>
#include "../include/graph.h"

/*
    Checks if two vertices are directly connected by an edge. Since
    edges are stored one-directionally, checks name1's adj list for
    name2, then name2's adj list for name1.
    
    @param *g - pointer to the graph
    @param name1 - name of the first vertex
    @param name2 - name of the second vertex
*/
int checkEdge(Graph *g, string name1, string name2){
    Vertex *v1 = getVertexByName(g, name1);
    Vertex *v2 = getVertexByName(g, name2);
    Pair *p;

    if (v1 != NULL){
        p = v1->adj;
        while (p != NULL){
            if (strcmp(p->name, name2) == 0)
                return 1;
            p = p->next;
        }
    }
    if (v2 != NULL){
        p = v2->adj;
        while (p != NULL){
            if (strcmp(p->name, name1) == 0)
                return 1;
            p = p->next;
        }
    }
    return 0;
}