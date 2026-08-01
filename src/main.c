#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/header.h"
#include "../include/graph.h"
#include "../include/heap.h"
#include "../include/heapedge.h"
#include "../include/queue.h"
#include "../include/stack.h"

void flush(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF); // Flush input buffer :>
}


int main(){
    Graph *graph = createGraph();
    int command = 0, weight, srcIdx, dstIdx;
    string input1 = "", input2 = "";
    EdgeLL *edgePrintList = malloc(sizeof(EdgeLL));
    edgePrintList->edges = NULL;

    do {
        scanf(" %d", &command);

        switch (command){
            case 1:
                scanf(" %256s", input1);
                addVertex(graph, input1);
                break;
            case 2:
                scanf(" %256s %256s %d", input1, input2, &weight);
                if (weight < 1 || weight > 100) printf("Weight must be from 1-100 only.\n");
                else if ((srcIdx = findVertex(graph, input1)) == -1) printf("Source vertex does not exist in graph.\n");
                else if ((dstIdx = findVertex(graph, input2)) == -1) printf("Dest. vertex does not exist in graph.\n");
                else  {
                    addEdge(graph, srcIdx, input2, weight); 
                    insertToPrintList(edgePrintList, input1, input2, weight);
                    addEdge(graph, dstIdx, input1, weight);
                }
                break;
            case 3:
                scanf(" %256s", input1);
                printf("%d\n", getDegree(graph, input1));
                break;
            case 4:
                scanf(" %256s %256s", input1, input2);
                printf("%d\n", checkEdge(graph, input1, input2));
                break;
            case 5:
                scanf(" %256s", input1);
                BFS(graph, input1);
                break;
            case 6:
                scanf(" %256s", input1);
                DFS(graph, input1);
                break;
            case 7:
                scanf(" %256s %256s", input1, input2);
                printf("%d\n", checkPath(graph, input1, input2));
                break;
            case 8:
                MST(graph);
                break;
            case 9: // OPTIONAL ONLY!!
                scanf(" %256s %256s", input1, input2);
                printf("shortestPath(%s, %s)", input1, input2);
                break;
            case 10: printGraph(graph, edgePrintList); break;
            case 11: destroyGraph(graph); break;
            default: 
                printf("Invalid command entered.\n"); 
                flush();
                break;
        }

        printf("\n");
    } while (command != 11);
}