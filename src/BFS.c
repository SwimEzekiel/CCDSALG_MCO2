#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/graph.h"
#include "../include/queue.h"
 
/*
    Performs a Breadth first traversal of the graph starting from the
    given vertex, printing each visited vertex's name on its own line.
 
    Since edges are stored one-directionally (addedge func), the graph is traversed as an undirected
    graph by gathering both outgoing and incoming neighbors.
    The queue itself only stores ints, so vertices are tracked by
    their index in the graph's vertex list rather than by name directly.
    When there's a choice between multiple unvisited neighbors, they are visited in lexicographical order.
 
    @param *g - pointer to the graph
    @param start - name of the vertex to start the traversal from
*/
void BFS(Graph *g, string start){
    int n = g->vertNum; // get total number of vertices in graph
    if (n == 0)         // check if graph empty
        return;
 
    // build an array of vertices
    // lexicographically sorted linked list
    Vertex **verts = malloc(n * sizeof(Vertex*));
    Vertex *cur = g->adjList;
    for (int i = 0; i < n; i++){
        verts[i] = cur;
        cur = cur->nextVert;
    }
 
    int startIdx = findVertex(g, start); // find index of starting vertex
    if (startIdx == -1){
        free(verts);
        return;
    }
 
    int *visited = calloc(n, sizeof(int)); // create visited array (initialized to 0 cus 0 is unvisited)
    Queue *q = createQueue();
 
    enqueue(q, startIdx);
    visited[startIdx] = 1;
 
    while (!isQueueEmpty(q)){ // start of BFS loop
        int curIdx = dequeue(q);
        printf("%s\n", verts[curIdx]->name);
 
        // create and gather all neighbors of curIdx in both directions
        int *neighbors = malloc(n * sizeof(int));
        int nCount = 0;
 
        Pair *p = verts[curIdx]->adj;
        while (p != NULL){
            neighbors[nCount++] = findVertex(g, p->name);
            p = p->next;
        }
 
        for (int i = 0; i < n; i++){ // scans every vertex's adj list for inc edges
            if (i == curIdx) continue;
            Pair *op = verts[i]->adj;
            while (op != NULL){
                if (strcmp(op->name, verts[curIdx]->name) == 0){
                    neighbors[nCount++] = i;
                    break;
                }
                op = op->next;
            }
        }
 
        // sort the gathered neighbors lexicographically by name using insertion sort
        for (int i = 1; i < nCount; i++){
            int key = neighbors[i];
            int j = i - 1;
            while (j >= 0 && strcmp(verts[neighbors[j]]->name, verts[key]->name) > 0){
                neighbors[j + 1] = neighbors[j];
                j--;
            }
            neighbors[j + 1] = key;
        }
 
        // visit unvisited neighbors in sorted order
        for (int i = 0; i < nCount; i++){
            int nIdx = neighbors[i];
            if (!visited[nIdx]){
                visited[nIdx] = 1;
                enqueue(q, nIdx);
            }
        }
 
        free(neighbors);
    }
 
    free(verts);
    free(visited);
    destroyQueue(q);
}