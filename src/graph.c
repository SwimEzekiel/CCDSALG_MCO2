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

// Don't forget to use this for validation!
int findVertex(Graph *g, string vert){
	int idx = -1;
	int ctr = 0;

	Vertex *cur = g->adjList;
	while (idx == -1 && cur != NULL){
		if (!strcmp(vert, cur->name)) idx = ctr;
		else {
			ctr++;
			cur = cur->nextVert;
		}
	}

	return idx;
}

int addEdge(Graph *g, int srcIdx, string dst, int weight){
	Pair *new = malloc(sizeof(Pair));
	Vertex *targetVert = g->adjList;
	Pair *prev = NULL;
	strcpy(new->name, dst);
	new->weight = weight;
	new->next = NULL;

	for (int ctr = 0; ctr < srcIdx; ctr++)
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

