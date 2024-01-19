#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "file_handling.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct definitions

typedef struct Node{
    int vertex, weight;
    struct Node* next;
} Node;

typedef struct {
    int vertices;
    Node** adjList;
} Graph;

//Function definitions

Graph* createGraph(UniqueCityList* uniquecitylist);

void outputTextGraph(Graph* graph, UniqueCityList* uniqueList);

void outputIndexGraph(Graph* graph);

#endif

