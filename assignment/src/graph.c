#include "graph.h"

/*--------- Concrete definitions ---------*/
struct Node{
    int vertex, energy;
    struct Node* next;
};

struct Graph{
    int vertices;
    Node** adjList;
};

/*---------- Private Functions ----------*/
Node* graph_CreateNode(int vertex, int weight);
void graph_AppendNode(Graph* graph, Node* node, int adjVertex);


/* Allocates memory for a node and sets its fields, returning its pointer*/
Node* graph_CreateNode(int vertex, int energy) {
    Node* node = malloc(sizeof(Node));

    node->vertex = vertex;
    node->energy = energy;
    node->next = NULL;

    return node;
}

/* Appends a selected node to the end of a specific linked list within an adjacency list */
void graph_AppendNode(Graph* graph, Node* node, int adjVertex){
    /* First checks if the linked list is empty, setting the head to the node if so */
    if(graph->adjList[adjVertex] == NULL){
        graph->adjList[adjVertex] = node;
    } else {
        /* If the list is not empty, traverses to the end and appends the node */
        Node* temp = graph->adjList[adjVertex];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = node;
    }
}

/* Reads the corresponding list of edges file and generates an adjacency list based
    graph */
Graph* graph_GenerateGraph(file_UniqueCityList* cityList, int signs){
    int i;
    FILE *file;
    char start[CITY_CHAR_SIZE], end[CITY_CHAR_SIZE];
    int energy, adjIndex, flippedIndex;

    /* Allocates memory for a single graph */
    Graph* graph = malloc(sizeof(Graph));

    graph->vertices = file_UniqueCityCount(cityList);

    /* Allocates memory for the number of cities that are present in the unique cities list */
    graph->adjList = malloc(graph->vertices * sizeof(Node*));

    /* Initialises the adjacency list with NULL pointers */
    for (i = 0; i < graph->vertices; i++) {
        graph->adjList[i] = NULL;
    }

    /* Error handling to check if the file exists within the project */
    if((file = fopen("energy-v22-2.txt", "r")) == NULL){
        printf("File not found.");
        exit(1);
    }

    rewind(file);

    /* For every single line within the energies text file, temporarily stores the
        (U, V) edge and its corresponding W weighting before passing them into the
        adjacency list */
    while(fscanf(file, "%s %s %d", start, end, &energy) != EOF){
        int adjIndex = file_UniqueCityIndex(start, cityList);
        int flippedIndex = file_UniqueCityIndex(end, cityList);

        /* For testing, sets all weightings to be positive if selected */
        if(signs) energy = abs(energy);

        Node* newNode = graph_CreateNode(flippedIndex, energy);
        Node* flippedNode = graph_CreateNode(adjIndex, energy);

        /* To generate an undirected graph, for each edge, a flipped version
            of the edge is added with the same weighting but opposite directions */
        graph_AppendNode(graph, newNode, adjIndex);
        graph_AppendNode(graph, flippedNode, flippedIndex);
    }

    fclose(file);

    return graph;
}

/* Displays the adjacency list graph, replacing all of the indexes with their
    corresponding city names to the user */
void graph_OutputTextGraph(Graph* graph, file_UniqueCityList* cityList){
    int i;
    for (i = 0; i < graph->vertices; i++) {
        Node* temp = graph->adjList[i];

        file_UniqueCityOutputCity(i, cityList);

        while (temp) {
            printf("->");
            file_UniqueCityOutputCity(temp->vertex, cityList);
            printf(" (%d) ", temp->energy);
            temp = temp->next;
        }
        printf("\n");
    }
}

/* Displays the adjacency list graph in index form to the user */
void graph_OutputIndexedGraph(Graph* graph){
    int i;
    for (i = 0; i < graph->vertices; i++) {
        Node* temp = graph->adjList[i];
        printf("%2d: " , i);
        while (temp) {
            printf("-> %3d (%3d) ", temp->vertex, temp->energy);
            temp = temp->next;
        }
        printf("\n\n");
    }
}

/* Returns the number of vertices in the graph */
int graph_GetVertices(Graph* graph){
    return graph->vertices;
}

/* Returns the number of edges that a specific vertex has */
int graph_GetNumberNodesInList(int index, Graph* graph){
    int count = 0;

    Node* temp = graph->adjList[index];

    while(temp){
        count++;
        temp = temp->next;
    }

    return count;
}

/* Returns the energy weighting of a specific edge in the adjacency list */
int graph_GetEnergyInList(int adjIndex, int nodeIndex, Graph* graph){
    int count = 0;

    Node* temp = graph->adjList[adjIndex];

    while(count != nodeIndex){
        count++;
        temp = temp->next;
    }

    return temp->energy;
}

/* Returns the vertex index of a specific edge in the adjacency list */
int graph_GetVertexInList(int adjIndex, int nodeIndex, Graph* graph){
    int count = 0;

    Node* temp = graph->adjList[adjIndex];

    while(count != nodeIndex){
        count++;
        temp = temp->next;
    }

    return temp->vertex;
}
