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
    Since edges are only stored once, we count both directions: edges where the vertex IS the
    source (its own adj list), and edges where it's the destination (it shows up in some other vertex's adj list).
    
    @param *g - pointer to the graph
    @param name - name of the vertex to check
*/
int getDegree(Graph *g, string name){
    Vertex *cur = g->adjList;
    Pair *p;
    int degree = 0;

    while (cur != NULL){
        p = cur->adj;

        if (strcmp(cur->name, name) == 0){
            while (p != NULL){
                degree++;
                p = p->next;
            }
        } else {
            while (p != NULL){
                if (strcmp(p->name, name) == 0)
                    degree++;
                p = p->next;
            }
        }

        cur = cur->nextVert;
    }
    return degree;
}
