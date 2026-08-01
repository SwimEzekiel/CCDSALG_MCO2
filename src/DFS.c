#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/graph.h"
#include "../include/stack.h"

/*
    Performs a depth-first traversal of the graph starting from the
    given vertex, printing each visited vertex's name on its own line.

    Uses the same strategy as BFS, just with a stack instead of a queue.
    Neighbors are gathered from both directions, sorted lexicographically, 
    then pushed in descending order so that when popped, 
    the lexicographically smallest unvisited neighbor comes out first, matching the tie-breaking rule.

    @param *g - pointer to the graph
    @param start - name of the vertex to start the traversal from
*/
void DFS(Graph *g, string start){
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
    Stack *s = createStack(n);

    push(s, startIdx);
    visited[startIdx] = 1;

    while (!isStackEmpty(s)){ // start of DFS loop
        int curIdx = pop(s, 0);
        printf("%s\n", verts[curIdx]->name);

        // gather all neighbors of curIdx, in both directions
        int *neighbors = malloc(n * sizeof(int));
        int nCount = 0;

        Pair *p = verts[curIdx]->adj;
        while (p != NULL){
            neighbors[nCount++] = findVertex(g, p->name);
            p = p->next;
        }

        for (int i = 0; i < n; i++){ // scans every other vertex's adj list for inc edges
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

        /* push unvisited neighbors in descending lexicographic order, so the
           smallest ends up on top of the stack (meaning itll be popped first)
        */
        for (int i = nCount - 1; i >= 0; i--){
            int nIdx = neighbors[i];
            if (!visited[nIdx]){    // marks current visited to avoid duplication
                visited[nIdx] = 1;
                push(s, nIdx);
            }
        }

        free(neighbors);
    }

    free(verts);
    free(visited);
    destroyStack(s);
}
