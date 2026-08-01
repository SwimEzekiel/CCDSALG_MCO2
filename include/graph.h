#ifndef graph_h
#define graph_h
#include "header.h"
#include "heap.h"

typedef struct Vertex Vertex;
typedef struct Pair Pair;
typedef struct EdgeLL EdgeLL;
typedef struct Edge Edge;

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

struct EdgeLL{
    int edgeNum;
    Edge *edges;
};

// Prototypes
Graph* createGraph();
void destroyGraph(Graph*);
void destroyGraph(Graph*);
void addVertex(Graph*, string);
int findVertex(Graph*, string);
int addEdge(Graph*, int idx, string, int weight);
void printVertices(Graph*);
void printEdges(EdgeLL*);
void printGraph(Graph*, EdgeLL*);
void MST(Graph*);
 
// Prototypes from getdegree
Vertex* getVertexByName(Graph*, string);
int getDegree(Graph*, string);

// Prototype from checkedge
int checkEdge(Graph*, string, string);

// Prototype for new printing
void insertToPrintList(EdgeLL*, string, string, int weight);
Vertex* getVertex(Graph*, int idx);

#endif