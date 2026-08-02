#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/graph.h"
#include "../include/queue.h"
 
/*
    Checks if there is a path from given vertex to the destination vertex by using BFS. 
    Uses BFS but only returns if destination is reachable.
 
    @param *g - pointer to the graph
    @param name1 - name of the starting vertex
    @param name2 - name of the vertex we're trying to reach
*/
int checkPath(Graph *g, string name1, string name2){
    int n = g->vertNum;     // get total number of vertices in graph
    if (n == 0)             // check if graph empty
        return 0;
 
    int idx1 = findVertex(g, name1); // convert V into idx
    int idx2 = findVertex(g, name2);
    if (idx1 == -1 || idx2 == -1) // doesn't exist
        return 0;
    if (idx1 == idx2) // same vertex
        return 1;
 
    int *visited = calloc(n, sizeof(int)); // create and fill array with 0's, 0 meaning unvisited
    Queue *q = createQueue();
    int found = 0;
 
    enqueue(q, idx1);
    visited[idx1] = 1;
 
    while (!isQueueEmpty(q) && !found){ // main loop
        int curIdx = dequeue(q);
 
        if (curIdx == idx2){    // check if destination found
            found = 1;
            break;
        }
 
        Vertex *curVert = getVertex(g, curIdx);
        Pair *p = curVert->adj;
        while (p != NULL){
            int neighborIdx = findVertex(g, p->name);
            if (!visited[neighborIdx]){
                visited[neighborIdx] = 1;
                enqueue(q, neighborIdx); // mark visited and add to queue
            }
            p = p->next;   // go to next neighbor
        }
    }
    //clean up
    free(visited);
    destroyQueue(q);
 
    return found;
}