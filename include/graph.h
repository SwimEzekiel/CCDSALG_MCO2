#include "header.h"

typedef struct {
    string name;
    Vertex *nextVert;
    Pair *adj;
} Vertex;

typedef struct {
	string name;
	int  weight;
	Pair *next;
} Pair;

typedef struct {
	int vertNum;
    Vertex *adjList;
} Graph;