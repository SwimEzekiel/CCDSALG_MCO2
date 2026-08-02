#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/graph.h"
#include "../include/stack.h"

/*
    Does a depth first search starting from the given vertex and prints each
    vertex name it visits, one per line.

    Same idea as the BFS, just with a Stack instead of a Queue.
    Checks graph if not empty, find start vertex, create visited array and stack then push current vertex. Start main loop,
    while stack is not empty, pop and print current Vertex. Gather the neighbors and sort them lexicographically, push them in 
    reverse order and loop till stack is empty. Clean up afterwards.

    @param *g - pointer to the graph
    @param start - name of the vertex to start from
*/
void DFS(Graph *g, string start){
    int n = g->vertNum;   // get total number of vertices in graph
    if (n == 0)           // check if graph empty
        return;

    int startIdx = findVertex(g, start);
    if (startIdx == -1) // vertex non existent
        return;

    int *visited = calloc(n, sizeof(int)); // creates and fill array with 0's, 0 meaning unvisited
    Stack *s = createStack(n);

    push(s, startIdx);
    visited[startIdx] = 1;

    while (!isStackEmpty(s)){ // main loop
        int curIdx = pop(s, 0);      // pop next vertex
        Vertex *curVert = getVertex(g, curIdx);

        printf("%s\n", curVert->name);

        // count neighbors first
        int neighborCount = 0;
        Pair *p = curVert->adj;
        while (p != NULL){
            neighborCount++;
            p = p->next;
        }

        // grab all the neighbor indexes
        int *neighbors = malloc(neighborCount * sizeof(int)); // create neighbor array
        p = curVert->adj;
        for (int i = 0; i < neighborCount; i++){
            neighbors[i] = findVertex(g, p->name);
            p = p->next;
        }

        // insertion sort the neighbors, smallest name ends up first in the array
        for (int i = 1; i < neighborCount; i++){
            int key = neighbors[i];
            Vertex *keyVert = getVertex(g, key);
            int j = i - 1;
            // shift bigger names to the right to make room for key
            while (j >= 0 && strcmp(getVertex(g, neighbors[j])->name, keyVert->name) > 0){
                neighbors[j + 1] = neighbors[j];
                j--;
            }
            neighbors[j + 1] = key;
        }

        // push neighbors from largest to smallest, so the smallest neighbor pop first
        for (int i = neighborCount - 1; i >= 0; i--){
            if (!visited[neighbors[i]]){
                visited[neighbors[i]] = 1;
                push(s, neighbors[i]);
            }
        }
        // clean up
        free(neighbors);
    }

    free(visited);
    destroyStack(s);
}