#include <string.h>
#include <stdlib.h>
#include "../include/graph.h"

/*
    Finds and returns the vertex with the given name and returns NULL if not found.
    
    @param *g - pointer to the graph
    @param name - name of the vertex to look for
*/
Vertex* getVertexByName(Graph *g, string name){
    Vertex *cur = g->adjList;

    while (cur != NULL){
        if (strcmp(cur->name, name) == 0)
            return cur;
        cur = cur->nextVert;
    }
    return NULL;
}

/*
    Computes the degree of a vertex, or how many edges touch it.
 
    @param *g - pointer to the graph
    @param name - name of the vertex to check
*/
int getDegree(Graph *g, string name){
    Vertex *v = getVertexByName(g, name);
    if (v == NULL) // vertex doesn't exist
        return 0;
 
    int degree = 0;
    Pair *p = v->adj;
    while (p != NULL){
        degree++;
        p = p->next;
    }
    return degree;
}
