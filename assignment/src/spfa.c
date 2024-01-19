#include "spfa.h"

void spfa(Graph* graph, int source, int destination, UniqueCityList* uniquelist){
    int V = graph->vertices;

    int distances[V];
    int previous[V];

    int inQueue[V + 1] = {0};

    int i;
    for (i = 0; i < V + 1; i++){
        distances[i] = INT_MAX;
        previous[V] = -1;
    }
    distances[source] = 0;

    Queue q;
    push(q, source);
    inQueue[source] = 1;
}

/*
SPFA(v):
    d[i] = inf for each vertex i
    p[i] = null
    d[v] = 0
    queue q
    q.push(v)
    while q is not empty
        u = q.front()
        q.pop()
        for each i in adj[u]
            if d[i] > d[u] + w(u,i)
                then
                  d[i] = d[u] + w(u,i)
                  p[i] = u
                if i is not in q
                    then q.push(i)
*/

/*
// Function to compute the SPF algorithm
void shortestPathFaster(int S, int V)
{
    // Create array d to store shortest distance
    int d[V + 1];

    // Boolean array to check if vertex
    // is present in queue or not
    bool inQueue[V + 1] = { false };

    // Initialize the distance from source to
    // other vertex as INT_MAX(infinite)
    for (int i = 0; i <= V; i++) {
        d[i] = INT_MAX;
    }
    d[S] = 0;

    queue<int> q;
    q.push(S);
    inQueue[S] = true;

    while (!q.empty()) {

        // Take the front vertex from Queue
        int u = q.front();
        q.pop();
        inQueue[u] = false;

        // Relaxing all the adjacent edges of
        // vertex taken from the Queue
        for (int i = 0; i < graph[u].size(); i++) {

            int v = graph[u][i].first;
            int weight = graph[u][i].second;

            if (d[v] > d[u] + weight) {
                d[v] = d[u] + weight;

                // Check if vertex v is in Queue or not
                // if not then push it into the Queue
                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }

    // Print the result
    print_distance(d, V);
}
*/
