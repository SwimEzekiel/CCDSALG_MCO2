#include "header.h"

typedef struct Vertex Vertex;
typedef struct Pair Pair;

struct Vertex{
    string name;
    Vertex *nextVert;
    Pair *adj;
};

struct Pair{
	string name;
	int  weight;
	Pair *next;
};

typedef struct {
	int vertNum;
    Vertex *adjList;
} Graph;

// Prototypes
Graph* createGraph();
void destroyGraph(Graph*);
void destroyGraph(Graph*);
void addVertex(Graph*, string);
int addEdge(Graph*, string, string, int weight);