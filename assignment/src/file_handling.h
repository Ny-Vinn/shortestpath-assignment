#ifndef FILE_HANDLING_H_INCLUDED
#define FILE_HANDLING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 50
#define CITY_PAIRS 10

//Struct definitions

typedef struct{
    char name[256];
} UniqueCity;

typedef struct{
    int numCities;
    UniqueCity* cityList;
} UniqueCityList;

typedef struct{
    char start[256];
    char end[256];
    int energy;
} CityLink;

typedef struct{
    int numLinks;
    CityLink* list;
} CityLinkList;

typedef struct{
    char start[256];
    char destination[256];
} CityPairList;


//Function definitions

CityLinkList* parseCitiesFile(CityLinkList* citylinks);

UniqueCityList* generateUniqueCities();

CityPairList* generateCityPairsList();

#endif
