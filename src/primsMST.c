#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/graph.h"

void MST(Graph *g){
    Graph *tree = createGraph();
    Vertex *cur;
    // New pair min heap
    
    /* PSEUDOCODE FOR PRIMS
    Do while graph does not have |V|-1 elements
        Insert neighbor vertices to graph: addVertex()
            If vertex already exists
                If new weight is less than in heap, edit key
            Else, insert to heap
        Extract minimum pair and add to graph [1]: addEdge(extractMin());
        Visit vertex
    
    HEAP SPECS:
        1. Should handle a new data struct called Edge (me na bahala)
        2. Heapify should base off of weight. If may tie, destination vertex names.
        3. Extract minimum should return the Edge for pseudocode [1]
    */
    
    printGraph(tree);
    destroyGraph(tree);
}