#ifndef SPFA_H_INCLUDED
#define SPFA_H_INCLUDED

#include "graph.h"
#include "file_handling.h"
#include "fifo_queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*--------- Public Function definitions ---------*/

void spfa(Graph* graph, int source, int destination, file_UniqueCityList* cityList);

#endif
