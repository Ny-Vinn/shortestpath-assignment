#include "graph.h"

Node* createNode(int vertex, int weight) {
    Node* link = malloc(sizeof(Node));
    link->vertex = vertex;
    link->weight = weight;
    link->next = NULL;
    return link;
}

int getCityIndex(char cityName[256], UniqueCityList* list){
    int i, index;
    for(i = 0; i < list->numCities; i++){
        if(!strcmp(list->cityList[i].name, cityName)) index = i;
    }
    return index;
}
// poggers comment test yappa yappa

char string[256] = "string test yappa yappa ";

void appendNode(Graph* graph, Node* node, int adjVertex){
    if(graph->adjList[adjVertex] == NULL){
            graph->adjList[adjVertex] = node;
        } else {
            Node* temp = graph->adjList[adjVertex];
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = node;
        }
}

Graph* createGraph(UniqueCityList* uniquecitylist){
    Graph* graph = malloc(sizeof(Graph));

    graph->vertices = uniquecitylist->numCities;

    graph->adjList = malloc(graph->vertices * sizeof(Node*));

    int i;
    for (i = 0; i < graph->vertices; i++) {
        graph->adjList[i] = NULL;
    }

    FILE *file;

    if((file = fopen("energy-v22-1.txt", "r")) == NULL){
        printf("File not found.");
        exit(1);
    }

    rewind(file);

    char start[256], end[256];
    int energy;

    while(fscanf(file, "%s %s %d", start, end, &energy) != EOF){
        int adjIndex = getCityIndex(start, uniquecitylist);
        int flippedIndex = getCityIndex(end, uniquecitylist);

        Node* newNode = createNode(flippedIndex, energy);
        Node* flippedNode = createNode(adjIndex, energy);

        appendNode(graph, newNode, adjIndex);

        //appendNode(graph, flippedNode, flippedIndex);
    }

    fclose(file);

    return graph;
}

void outputTextGraph(Graph* graph, UniqueCityList* uniqueList){
    int i;
    for (i = 0; i < graph->vertices; i++) {
        Node* temp = graph->adjList[i];
        printf("\n%s ", uniqueList->cityList[i].name);
        while (temp) {
            printf("-> %s (%d) ", uniqueList->cityList[temp->vertex].name, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

void outputIndexGraph(Graph* graph){
    int i;
    for (i = 0; i < graph->vertices; i++) {
        Node* temp = graph->adjList[i];
        printf("%2d: " ,i);
        while (temp) {
            printf("-> %3d (%3d) ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n\n");
    }
}
