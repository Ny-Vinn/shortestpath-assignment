#include "spfa.h"

/* Shortest Path Faster algorithm implementation with an adjacency list graph */

void spfa(Graph* graph, int source, int destination, file_UniqueCityList* cityList){
    int u, i, v, w, traverse;
    int V = graph_GetVertices(graph);

    fifo_queue* q;

    int distances[V];

    int previous[V];

    int inQueue[V + 1];

    /* Initialises the inQueue array with int representations of boolean FALSE */
    for (i = 0; i < V + 1; i++){
        inQueue[i] = 0;
    }

    /* Initialises the distances array with effectively INFINITE values from the source
        and then sets the previous array to NULL values in an int representation */
    for (i = 0; i < V; i++){
        distances[i] = INT_MAX;
        previous[V] = -1;
    }

    /* Defines the source vertex within the distances array to be compared from */
    distances[source] = 0;

    /* Initalises a default empty queue */
    q = createQueue(q);

    /* Pushes the source into the queue to be the first vertex to be relaxed */
    push(q, source);
    inQueue[source] = 1;

    /* Main SPFA algorithm */
    /* Will continue to relax any vertexes until the queue is empty */
    while(!isEmpty(q)){
        u = pop(q);

        for(i = 0; i < graph_GetNumberNodesInList(u, graph); i++){
            v = graph_GetVertexInList(u, i, graph);
            w = graph_GetEnergyInList(u, i, graph);

            if(distances[v] > distances[u] + w){
                distances[v] = distances[u] + w;
                previous[v] = u;

                if(!inQueue[v]) {
                    push(q, v);
                    inQueue[v] = 1;
                }
            }
        }
    }

    /* Displays the shortest path from the source node to the destination node by traversing
        through each of the parents of the nodes within the path */
    puts(" ");
    traverse = destination;
    printf("Path from %s to %s = %s " , file_UniqueCityIndexToCity(source, cityList),  file_UniqueCityIndexToCity(destination, cityList),  file_UniqueCityIndexToCity(destination, cityList));
    while(traverse != source){
        traverse = previous[traverse];
        printf("<- %s " ,file_UniqueCityIndexToCity(traverse, cityList));
    }
    printf("\nTotal Energy: %d", distances[destination]);
    puts(" ");
}

