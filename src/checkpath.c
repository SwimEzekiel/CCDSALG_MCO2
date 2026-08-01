#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/graph.h"
#include "../include/queue.h"

/*
    Checks if there is any path connecting name1 to name2, by running
    a silent BFS from name1 and seeing if name2 gets visited. Order of
    traversal doesn't matter.

    Parameters:
    @param *g - pointer to the graph
    @param name1 - name of the starting vertex
    @param name2 - name of the vertex to check reachability to
*/
int checkPath(Graph *g, string name1, string name2){
    int n = g->vertNum; // get total number of vertices in graph
    if (n == 0)         // check if graph empty
        return 0;

    int idx1 = findVertex(g, name1); // convert names to indexes
    int idx2 = findVertex(g, name2);
    if (idx1 == -1 || idx2 == -1)
        return 0;
    if (idx1 == idx2)
        return 1;

    // build an array of vertices
    // lexicographically sorted linked list
    Vertex **verts = malloc(n * sizeof(Vertex*));
    Vertex *cur = g->adjList;
    for (int i = 0; i < n; i++){
        verts[i] = cur;
        cur = cur->nextVert;
    }

    int *visited = calloc(n, sizeof(int)); // create visited array (initialized to 0 cus 0 is unvisited)
    Queue *q = createQueue();
    int found = 0;

    enqueue(q, idx1); // start silent BFS
    visited[idx1] = 1;

    while (!isQueueEmpty(q) && !found){ // main loop
        int curIdx = dequeue(q);

        if (curIdx == idx2){ // if current is destination, done
            found = 1;
            break;
        }

        // gather neighbors from both directions
        Pair *p = verts[curIdx]->adj;
        while (p != NULL){
            int nIdx = findVertex(g, p->name);
            if (!visited[nIdx]){
                visited[nIdx] = 1;
                enqueue(q, nIdx);
            }
            p = p->next;
        }

        for (int i = 0; i < n; i++){ //look for reverse connecitons
            if (i == curIdx) continue;
            Pair *op = verts[i]->adj;
            while (op != NULL){
                if (strcmp(op->name, verts[curIdx]->name) == 0){ // does this vertex point to the current vertex ?
                    if (!visited[i]){                            // if yes then current can reach that vertex
                        visited[i] = 1;
                        enqueue(q, i);
                    }
                    break;
                }
                op = op->next;
            }
        }
    }

    free(verts);
    free(visited);
    destroyQueue(q);

    return found;
}
