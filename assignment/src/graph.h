#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "file_handling.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--------- Opaque Struct definitions ---------*/

typedef struct Node Node;
typedef struct Graph Graph;


/*--------- Public Function definitions ---------*/

Graph* graph_GenerateGraph(file_UniqueCityList* cityList, int signs);

void graph_OutputTextGraph(Graph* graph, file_UniqueCityList* cityList);

void graph_OutputIndexedGraph(Graph* graph);

int graph_GetVertices(Graph* graph);

int graph_GetNumberNodesInList(int index, Graph* graph);

int graph_GetEnergyInList(int adjIndex, int nodeIndex, Graph* graph);

int graph_GetVertexInList(int adjIndex, int nodeIndex, Graph* graph);

#endif

