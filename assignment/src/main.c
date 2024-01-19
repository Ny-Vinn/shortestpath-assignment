#include <stdio.h>
#include <stdlib.h>

#include "file_handling.h"
#include "graph.h"
#include "bellmanford.h"
#include "spfa.h"

/* Program which parses two text files, compiling the data into a graph format and computes a pathing
   algorithm to find the shortest path between test pairs of cities. */

int main() {
    int i;
    file_UniqueCityList* cityList;
    file_PairList* pairList;
    Graph* graph;

    int signs = -1;

    int menu_MainChoice;

    int menu_OutputExit;
    int menu_OutputChoice;

    int menu_EditExit;
    int menu_EditChoice;

    int menu_AlgorithmExit;
    int menu_AlgorithmChoice;


    cityList = file_GenerateUniqueCities();


    pairList = file_GeneratePairList(cityList);


    /* This exists mainly for testing purposes due to not solving the issue of negative cycles
        within the algorithms as otherwise the algorithms do not function or function infinitely */
    while(signs != 1 && signs != 0){
        printf("(Testing) Make graph weightings all positive? (1 = Yes, 0 = No): \n");
        scanf("%d", &signs);
    }

    graph = graph_GenerateGraph(cityList, signs);

    /* Menu System to navigate through program and be able to use the abstract functions of the graph ADT */
    /* Full functionality never fully finished, certain menus are left empty as placeholders */
    printf("----- Y3889903 Pathing Program -----\n");
    printf("(Might need to enter number twice, interface is slightly bugged)\n");
    while(1) {
        printf("1) - Debug / Output \n");
        printf("2) - Edit / Append \n");
        printf("3) - Run Algorithm(s) \n");
        printf("4) - Exit \n");
        scanf("%d", &menu_MainChoice);

        switch(menu_MainChoice){
        case 1:
            while(!menu_OutputExit){
                printf("\n-------------------------------\n");
                printf("    1) - Output Graph (Indexed)\n");
                printf("    2) - Output Graph (Text) \n");
                printf("    3) - Output List of Cities \n");
                printf("    4) - Output Test Pairs (Indexed) \n");
                printf("    5) - Exit \n");
                scanf("%d", &menu_OutputChoice);

                printf("\n");

                switch(menu_OutputChoice){

                case 1:
                    graph_OutputIndexedGraph(graph);
                    break;

                case 2:
                    graph_OutputTextGraph(graph, cityList);
                    break;

                case 3:
                    file_UniqueCityOutput(cityList);
                    break;

                case 4:
                    file_PairListOutput(pairList);
                    break;

                case 5:
                    printf("...Exiting Output Menu...\n\n");
                    menu_OutputExit = 1;
                    break;

                default:
                    printf("...Error, not one of the choices...\n");
                    break;
                }
            }
            menu_OutputExit = 0;
            break;

        case 2:
            while(!menu_EditExit){
                printf("\n-------------------------------\n");
                printf("    1) - Append Edge to Graph \n");
                printf("    2) - Append Vertex and City to Graph \n");
                printf("    3) - Append Test Pair \n");
                printf("    4) - Exit \n");
                scanf("%d", &menu_EditChoice);

                printf("\n");

                switch(menu_EditChoice){
                case 1:

                    break;

                case 2:

                    break;

                case 3:

                    break;

                case 4:
                    printf("...Exiting Edit Menu...\n\n");
                    menu_EditExit = 1;
                    break;

                default:
                    printf("...Error, not one of the choices..\n.");
                    break;
                }
            }
            menu_EditExit = 0;
            break;

        case 3:
            while(!menu_AlgorithmExit){

                printf("\n-------------------------------\n");
                printf("    1) - Run BellmanFord \n");
                printf("    2) - Run SPFA \n");
                printf("    3) - Exit \n");
                scanf("%d", &menu_AlgorithmChoice);

                printf("\n");

                switch(menu_AlgorithmChoice) {
                case 1:
                    printf("Running BellmanFord Algorithm on selected test Pairs: \n");

                    for(i = 0; i < file_PairListGetNofPairs(pairList); i++){
                        bellmanFord(graph, file_PairListGetSource(i, pairList), file_PairListGetDestination(i, pairList), cityList);
                    }
                    break;

                case 2:
                    printf("Running SPFA Algorithm on selected test Pairs: \n");

                    for(i = 0; i < file_PairListGetNofPairs(pairList); i++){
                        spfa(graph, file_PairListGetSource(i, pairList), file_PairListGetDestination(i, pairList), cityList);
                    }
                    break;

                case 3:
                    printf("...Exiting Algorithm Menu...\n\n");
                    menu_AlgorithmExit = 1;
                    break;

                default:
                    printf("...Error, not one of the choices..\n.");
                    break;
                }
            }
            menu_AlgorithmExit = 0;
            break;

        case 4:
            printf("\nExiting Program...\n");
            return EXIT_SUCCESS;
            break;

        default:
            printf("...Error, not one of the choices...\n");
            break;
        }
    }
}
