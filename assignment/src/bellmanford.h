#ifndef BELLMANFORD_H_INCLUDED
#define BELLMANFORD_H_INCLUDED

#include "graph.h"
#include "file_handling.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*--------- Public Function definitions ---------*/

void bellmanFord(Graph* graph, int source, int destination, file_UniqueCityList* cityList);

#endif
