#include <string.h>
#include "../include/graph.h"

Graph* createGraph(){
	Graph *ret = malloc(sizeof(Graph));
	ret->adjList = malloc(sizeof(Vertex));
	ret->vertNum = 0;
	return ret;
}
void addVertex(Graph* g, string vName){
	Vertex *new = malloc(sizeof(Vertex));

	strcpy(new->name, vName);
	new->adj = new->nextVert = NULL;

	if (!g->vertNum)
		g->adjList = new;
	else {
		Vertex *cur = g->adjList;
		while (cur->nextVert != NULL)
			cur = cur->nextVert;
		cur->nextVert = new;
	}
	g->vertNum++;
}

int addEdge(Graph *g, string src, string dst, int weight){
	if (weight < 0) return 1; // error 1: weight cannot be negative

	int srcIdx = -1;
	int ctr = 0;
	Pair *cur = g->adjList;
	while (srcIdx == -1 && cur != NULL){
		if (!strcmp(src, cur->name)) srcIdx = ctr;
		else {
			ctr++;
			cur = cur->nextVert;
		}
	}

	if (srcIdx == -1) return 2; // error 2: source vertex not in adjList

	int dstIdx = -1;
	ctr = 0;
	cur = g->adjList;
	while (dstIdx == -1 && cur != NULL){
		if (!strcmp(dst, cur->name)) dstIdx = ctr;
		else {
			ctr++;
			cur = cur->nextVert;
		}
	}

	if (dstIdx == -1) return 3; // error 3: dest vertex not in adjList

	/***********************************************************************/
	Pair *new = malloc(sizeof(Pair));
	strcpy(new->name, dst);
	new->weight = weight;
	new->adj = new->nextVert = NULL;
}
