#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/graph.h"

Graph* createGraph(){
	Graph *ret = malloc(sizeof(Graph));
	ret->adjList = NULL;
	ret->vertNum = 0;
	return ret;
}

void destroyGraph(Graph *g){
	Vertex *curV = g->adjList, *temV;
	Pair *curP = g->adjList->adj, *temP;

	while (curV != NULL){
		while (curP != NULL){
			temP = curP;
			free(curP);
			curP = temP->next;
		}
		temV = curV;
		free(curV);
		curV = temV->nextVert;
	}

	free(g);
}

void addVertex(Graph* g, string vName){
	Vertex *new = malloc(sizeof(Vertex));

	strcpy(new->name, vName);
	new->adj = NULL;
	new->nextVert = NULL;

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
	if (weight < 0) return 1; 
	else if (weight > 100) return 1; // error 1: weight must be in bounds

	int srcIdx = -1;
	int ctr = 0;
	Vertex *cur = g->adjList;
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
	Vertex *targetVert = g->adjList;
	Pair *prev = NULL;
	strcpy(new->name, dst);
	new->weight = weight;
	new->next = NULL;

	for (ctr = 0; ctr < srcIdx; ctr++)
		targetVert = targetVert->nextVert;
	
	if (targetVert->adj == NULL){
		targetVert->adj = new;
	} else {
		prev = targetVert->adj;
		while (prev->next != NULL){
			prev = prev->next;
		}
		prev->next = new;
	}

	return 0; // 0 means successful
}

