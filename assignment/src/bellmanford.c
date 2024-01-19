#include "bellmanford.h"

/* pseudocode
function bellmanFord(G, S)
  for each vertex V in G
    distance[V] <- infinite
      previous[V] <- -1
  distance[S] <- 0

  for each vertex V in G
    for each edge (U,V) in G
      tempDistance <- distance[U] + edge_weight(U, V)
      if tempDistance < distance[V]
        distance[V] <- tempDistance
        previous[V] <- U

  for each edge (U,V) in G
    If distance[U] + edge_weight(U, V) < distance[V}
      Error: Negative Cycle Exists
*/

void bellmanFord(Graph* graph, int source, int destination, UniqueCityList* uniquelist){
    int V = graph->vertices;

    Node* crawl;
    int distances[V];
    int previous[V];

    int i;
    for(i = 0; i < V; i++){
        distances[i] = INT_MAX;
        previous[i] = -1;
    }

    distances[source] = 0;

    int u, v, w;
    for(i = 0; i < V - 1; i++){
        for(u = 0; u < V; u++){
            crawl = graph->adjList[u];
            while(crawl != NULL){
                v = crawl->vertex;
                w = crawl->weight;

                if (distances[u] != INT_MAX && (distances[u] + w < distances[v])) {
                    distances[v] = distances[u] + w;
                    previous[v] = u;
                }
                crawl = crawl->next;
            }
        }
    }


    for (i = 0; i < V; ++i) {
        crawl = graph->adjList[i];

        while (crawl != NULL) {
            if (distances[i] + crawl->weight < distances[crawl->vertex]) {
                puts("Negative Cycle Detected.");
            }

            crawl = crawl->next;
        }
    }

    printf("\n\nVertex    Shortest Distance to Vertex %d     Parent Vertex\n", source);
    for (u = 0; u < V; ++u) {
        printf("%d         %d                                 %d\n", u, distances[u], previous[u]);
    }

    /*
    puts(" ");
    int temp = destination;
    printf("Path: from %s to %s = %s " , uniquelist->cityList[source].name, uniquelist->cityList[destination].name, uniquelist->cityList[destination].name);
    while(temp != source){
        temp = previous[temp];
        printf("<- %s " ,uniquelist->cityList[temp].name);
    }
    puts(" ");
    */
}
