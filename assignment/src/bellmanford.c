#include "bellmanford.h"

/* Implementation of the bellman ford algorithm with the use of an adjacency list */

void bellmanFord(Graph* graph, int source, int destination, file_UniqueCityList* cityList){
    int V = graph_GetVertices(graph);
    int u, v, w, traverse, i, x, nodesInList;

    /* Distances array stores all of the current shortest distances from the source */
    int distances[V];

    /* Previous array is used to store the parents of each of the relaxed nodes to be used
        in traversing and finding the shortest path from the source to the destination nodes */
    int previous[V];

    /* Initialises the distance array with a theoretical infinite value
        and the previous array with practically NULL */
    for(i = 0; i < V; i++){
        distances[i] = INT_MAX;
        previous[i] = -1;
    }

    /* Defines the source node within the distances array */
    distances[source] = 0;

    /* The shortest path will be found within V - 1 loops over all of the edges
        (provided that the graph contains no negative cycles) */
    for(i = 0; i < V - 1; i++){
        /* (For each linked list within the adjacency list) */
        for(u = 0; u < V; u++){
            nodesInList = graph_GetNumberNodesInList(u, graph);
            for(x = 0; x < nodesInList; x++){

                v = graph_GetVertexInList(u, x, graph);
                w = graph_GetEnergyInList(u, x, graph);

                /* Ignores any already INFINITE values within the current set of shortest distances
                    since this can cause an overflow into a negative INT_MAX */
                if (distances[u] != INT_MAX && (distances[u] + w < distances[v])) {
                    /* Relaxes the edge since it is a shorter distance */
                    distances[v] = distances[u] + w;
                    previous[v] = u;
                }
            }
        }
    }

    /* If the shortest distances change at any point after another loop over all of the edges
        then a negative cycle exists */
    for (i = 0; i < V; ++i) {
        nodesInList = graph_GetNumberNodesInList(i, graph);
        for(x = 0; x < nodesInList; x++){
            if (distances[i] + graph_GetEnergyInList(i, x, graph) < distances[graph_GetVertexInList(i, x, graph)]) {
                puts("Negative Cycle Detected.");
            }
        }
    }

    /* Follows along each of the parents from the destination to the source node and outputs the path
        using the cityList to give each of the cities their corresponding names */
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

