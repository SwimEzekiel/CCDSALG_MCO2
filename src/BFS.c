#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/graph.h"
#include "../include/queue.h"
 
/*
    Does a breadth first search starting from given vertex and prints
    each vertex name it visits, one per line.
    
    Checks graph if not empty, finds start vertex, create visited array and queue then enqueue current/starting vertex. Main loop starts,
    while queue is not empty, dequeues and prints current vertex. Gather the neighbors and sort them lexicographically, enqueues the 
    unvisited neighbors, and loop till queue is empty. Clean up afterwards.
 
    @param *g - pointer to the graph
    @param start - name of the vertex to start from
*/
void BFS(Graph *g, string start){
    int n = g->vertNum;     // get total number of vertices in graph
    if (n == 0)             // check if graph empty
        return;
 
    int startIdx = findVertex(g, start);
    if (startIdx == -1) // vertex doesn't exist
        return;
 
    int *visited = calloc(n, sizeof(int)); // create and fill array with 0's, 0 meaning unvisited
    Queue *q = createQueue();
 
    enqueue(q, startIdx);
    visited[startIdx] = 1;
 
    while (!isQueueEmpty(q)){ // main loop
        int curIdx = dequeue(q);
        Vertex *curVert = getVertex(g, curIdx);
 
        printf("%s\n", curVert->name);
 
        //count how many neighbors 
        int neighborCount = 0;
        Pair *p = curVert->adj;
        while (p != NULL){
            neighborCount++;
            p = p->next;
        }
 
        // put all the neighbor indexes into an array
        int *neighbors = malloc(neighborCount * sizeof(int)); // create neighbor array
        p = curVert->adj;
        for (int i = 0; i < neighborCount; i++){
            neighbors[i] = findVertex(g, p->name);
            p = p->next;
        }
 
        // insertion sort the neighbors so they are visisted in lexicographical order
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
 
        // enqueue any neighbor that hasn't been visited yet
        for (int i = 0; i < neighborCount; i++){
            if (!visited[neighbors[i]]){
                visited[neighbors[i]] = 1;
                enqueue(q, neighbors[i]);
            }
        }
        // cleanup
        free(neighbors);
    }
 
    free(visited);
    destroyQueue(q);
}