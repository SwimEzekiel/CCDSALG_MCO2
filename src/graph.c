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
		Vertex *prev = NULL;
		int diff = strcmp(vName, cur->name);
		while (diff > 0 && cur != NULL){
			diff = strcmp(vName, cur->name);

			if (diff > 0) {
				prev = cur;
				cur = cur->nextVert;
			}
		}
		
		if (diff == 0);
		else if (prev == NULL) { // New must be first vert: works!
			new->nextVert = g->adjList;
			g->adjList = new;
		} else if (cur == NULL) { // New must be last vert
			prev->nextVert = new;
		} else { // Somewhere in between
			prev->nextVert = new;
			new->nextVert = cur;
		}
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
	Pair *cur = NULL, *prev = NULL;
	int diff;

	strcpy(new->name, dst);
	new->weight = weight;
	new->next = NULL;

	for (int ctr = 0; ctr < srcIdx; ctr++)
		targetVert = targetVert->nextVert;
	
	if (targetVert->adj == NULL){
		targetVert->adj = new;
	} else {
		cur = targetVert->adj;
		diff = strcmp(dst, cur->name);
		while (diff > 0 && cur != NULL){
			diff = strcmp(dst, cur->name);

			if (diff > 0){
				prev = cur;
				cur = cur->next;
			}
		}

		if (diff == 0);
		else if (prev == NULL){
			new->next = targetVert->adj;
			targetVert->adj = new;
		} else if (cur == NULL){
			prev->next = new;
		} else {
			prev->next = new;
			new->next = cur;
		}
	}

	return 0; // 0 means successful
}

