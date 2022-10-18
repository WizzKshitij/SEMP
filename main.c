#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
int main() {
    FILE *f;
	f = fopen("sample.txt", "r");
	graphList g1;
	initGraphList(&g1,f);
		dijkstra(&g1,0,4);
	return 0;
}
