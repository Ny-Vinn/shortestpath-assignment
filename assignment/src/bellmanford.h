#ifndef BELLMANFORD_H_INCLUDED
#define BELLMANFORD_H_INCLUDED

#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void bellmanFord(Graph* graph, int source, int destination, UniqueCityList* uniquelist);

#endif
