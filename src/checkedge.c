#include <string.h>
#include <stdlib.h>
#include "../include/graph.h"
 
/*
    Checks if two vertices are directly connected by an edge.
 
    @param *g - pointer to the graph
    @param name1 - name of the first vertex
    @param name2 - name of the second vertex
*/
int checkEdge(Graph *g, string name1, string name2){
    Vertex *v1 = getVertexByName(g, name1);
    if (v1 == NULL) // vertex doesn't exist
        return 0;
 
    Pair *p = v1->adj;
    while (p != NULL){
        if (strcmp(p->name, name2) == 0)
            return 1;
        p = p->next;
    }
    return 0;
}