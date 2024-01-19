#ifndef SPFA_H_INCLUDED
#define SPFA_H_INCLUDED

#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//function definitions

void spfa(Graph* graph, int source, int destination, UniqueCityList* uniquelist);

#endif
