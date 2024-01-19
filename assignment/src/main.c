#include <stdio.h>
#include <stdlib.h>

#include "file_handling.h"
#include "graph.h"
#include "bellmanford.h"
#include "spfa.h"

int main() {
    //CityPairList* pairs = generateCityPairsList();

    /*
    int i;
    for(i = 0; i < 3; i++){
        printf("%s -> %s\n" ,pairs[i].start, pairs[i].destination);
    }
    */

    UniqueCityList* uniqueList = generateUniqueCities();

    //printf("Number of unique cities: %d\n" ,uniqueList->numCities);

    /*
    int i;
    for(i = 0; i < uniqueList->numCities; i++){
        printf("%d {%s}\n", i, uniqueList->cityList[i].name);
    }
    */

    Graph* graph = createGraph(uniqueList);

    //outputTextGraph(graph, uniqueList);

    //outputIndexGraph(graph);

    //bellmanFord(graph, 0, 19, uniqueList);

    //spfa(graph, 0, 19, uniqueList);

    return 0;
}
