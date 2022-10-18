#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int vertex,weight;
    struct node* next;
} node;

typedef struct graph{
    int vertices;
    node** arr;
}graphList;

typedef struct edge {
	int weight, start, end;
} edge;
void append(node **l, int vertex,int data);
void initGraphList(graphList *g,FILE *f);
void dijkstra(graphList *g, int src,int dest);
