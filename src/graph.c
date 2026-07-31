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
	Pair *curP, *temP;
	if (curV != NULL) curP = g->adjList->adj;

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
	strcpy(new->name, dst);
	new->weight = weight;
	new->next = NULL;

	Pair *rev = malloc(sizeof(Pair));
	rev->weight = weight;
	rev->next = NULL;

	Vertex *targetVert = g->adjList;
	Pair *prev = NULL;
	
	for (int ctr = 0; ctr < srcIdx; ctr++)
		targetVert = targetVert->nextVert;
	strcpy(rev->name, targetVert->name);
	
	if (targetVert->adj == NULL){
		targetVert->adj = new;
	} else {
		prev = targetVert->adj;
		while (prev->next != NULL){
			prev = prev->next;
		}
		prev->next = new;
	}

	targetVert = g->adjList;
	while (strcmp(targetVert->name, dst))
		targetVert = targetVert->nextVert;
	
	if (targetVert->adj == NULL){
		targetVert->adj = rev;
	} else {
		prev = targetVert->adj;
		while (prev->next != NULL){
			prev = prev->next;
		}
		prev->next = rev;
	}

	return 0; // 0 means successful
}

void printVertices(Graph *g){
    Vertex *cur = g->adjList;
    while (cur != NULL){
        printf(cur->name);
        if (cur->nextVert != NULL) printf(", ");
        cur = cur->nextVert;
    }
    printf("}\n");
}
void printEdges(Graph *g){
    Vertex *curV = g->adjList;
    Pair   *curP = NULL;

    if (curV != NULL && curV->adj != NULL) curP = curV->adj;

    while (curV != NULL){
        if(curV == g->adjList && curV->adj != NULL) printf("\n"); // Runs only on first edge!
        curP = curV->adj;
        while (curP != NULL){
            printf("     (%s, %s, %d),\n", curV->name, curP->name, curP->weight);
            curP = curP->next;
        }
        curV = curV->nextVert;
    }
    printf("}\n");
}
void printGraph(Graph *g){
    printf("G = (V,E)\n");
    printf("V = {");
    printVertices(g);
    printf("E = {");
    printEdges(g);
}