#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

#include <ctype.h>
#include "limits.h"
void append(node **l, int vertex,int data) {
	node *newnode, *p;
	newnode = (node *)malloc(sizeof(node));
	if(!newnode)
		return;
	newnode -> vertex = vertex;
	newnode -> next = NULL;
	newnode ->weight = data;
	if(*l == NULL) {
		*l = newnode;
		return;
	}
	p = *l;
	while(p -> next)
		p = p -> next;
	p -> next = newnode;
	return;
}

void initGraphList(graphList *g,FILE *f) {
	int vertices, data;

	fscanf(f, "%d", &vertices);
	g -> vertices = vertices;
	g -> arr = (node **)malloc(sizeof(node *) * vertices);
	for(int i = 0; i < g -> vertices; i++) {
		g -> arr[i] = NULL;
		for(int j = 0; j < g -> vertices; j++) {
			if(fscanf(f, "%d", &data) != EOF && data != 0)
				append(&(g -> arr[i]), j,data);
		}
	}
	return;
}
void dijkstra(graphList *g, int src,int dest){
    int distance[g->vertices];
    int visited[g->vertices];
    for(int i=0;i<g->vertices;i++){
        visited[i]=0;
        distance[i]=INT_MAX;
    }

    distance[src]=0;
    for(int i=0;i<g->vertices;i++){
        int min=INT_MAX;
        int minIndex;
        for(int j=0;j<g->vertices;j++){
            if(visited[j]==0 && distance[j]<min){
                min = distance[j];
                minIndex=j;
            }
        }
        visited[minIndex]=1;
        node *p;
        p=g->arr[minIndex];
        p=p->next;
        while(p){
            if(!visited[p->vertex] && distance[minIndex]!=INT_MAX && (distance[minIndex] + p->weight < distance[p->vertex]))
                distance[p->vertex] = distance[minIndex] + p->weight;
            p=p->next;
        }
    }
    printf("\n");
    for(int j=0;j<g->vertices;j++){
        if(j==dest){
            printf("From %d to %d shortest distance is: %d ",src,dest,distance[dest]);
        }
    }
    printf("\nDistance array for Dijkstra's is:");
    for (int i = 0; i < g->vertices; i++)
        printf(" %d", distance[i]);
    printf("\n");

}
