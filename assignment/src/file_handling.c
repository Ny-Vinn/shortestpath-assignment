#include "file_handling.h"

CityLink* createCityLink(char start[256], char end[256], int energy){
        CityLink* link = malloc(sizeof(CityLink));
        strcpy(link->start, start);
        strcpy(link->end, end);
        link->energy = energy;
        return link;
}

UniqueCityList* generateUniqueCities(){
    FILE *file;

    if((file = fopen("energy-v22-1.txt", "r")) == NULL){
        printf("File not found.");
        exit(1);
    }

    rewind(file);

    UniqueCityList* cities = malloc(sizeof(UniqueCityList));
    cities->cityList = malloc(MAX_CITIES * sizeof(UniqueCity));

    int inList = 0;
    cities->numCities = 0;

    int i;
    char city[256];

    while(fscanf(file, "%s %*s %*d", city) != EOF){
        for(i = 0; i < cities->numCities; i++){
            if(strcmp(cities->cityList[i].name, city) == 0) {
                inList = 1;
            }
        }

        if(!inList){
            strcpy(cities->cityList[cities->numCities].name, city);
            cities->numCities++;
        }

        inList = 0;
    }

    return cities;
}

CityPairList* generateCityPairsList(){
    FILE *file;

    if((file = fopen("citypairs.txt", "r")) == NULL){
        printf("File not found.");
        exit(1);
    }

    rewind(file);

    CityPairList* pairs = malloc(CITY_PAIRS * sizeof(CityPairList));

    char start[256];
    char destination[256];
    int numPairs = 0;

    while(fscanf(file, "%s %s", start, destination) != EOF){
        strcpy(pairs[numPairs].start, start);
        strcpy(pairs[numPairs].destination, destination);
        numPairs++;
    }

    return pairs;
}
