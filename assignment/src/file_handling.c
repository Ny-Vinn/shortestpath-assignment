#include "file_handling.h"

/*--------- Concrete definitions ---------*/
struct file_EdgeList{
    int edgeStart, edgeEnd, edgeEnergy;
    struct file_EdgeList* next;
};

struct file_PairList{
    int pairSource, pairDestination;
    struct file_PairList* next;
};

struct file_UniqueCityList{
    char cityName[CITY_CHAR_SIZE];
    struct file_UniqueCityList* next;
};


/*---------- Private Functions ----------*/

file_UniqueCityList* file_UniqueCityConstructor(char city[CITY_CHAR_SIZE]);
int file_UniqueCityInList(file_UniqueCityList* cityList, char city[CITY_CHAR_SIZE]);
file_UniqueCityList* file_UniqueCityAppend(file_UniqueCityList* cityList, file_UniqueCityList* newCity);


file_PairList* file_PairListConstructor(int start, int destination);
file_PairList* file_PairListAppend(file_PairList* pairList, file_PairList* newPair);

/*--------------------------------------*/


/* -------------------- Unique Cities -------------------- */

/* Function which generates a list of all of the individual
    cities from the set of edges within the file to be used for indexing */
file_UniqueCityList* file_GenerateUniqueCities(){
    FILE* file;
    file_UniqueCityList* cityList = NULL;
    file_UniqueCityList* newCity;

    int inList = 0;

    char city[CITY_CHAR_SIZE];

    /* Error handling to check if the corresponding file exists */
    if((file = fopen("energy-v22-2.txt", "r")) == NULL){
        printf("File not found.");
        exit(1);
    }

    rewind(file);

    /* Reads each line of the text file until end of file
        and temporarily stores the first cities' name.
        (Ignoring the other 2 elements of the lines) */
    while(fscanf(file, "%s %*s %*d", city) != EOF){

        /* For each city name, checks if it already exists in the
            current list of non-duplicate cities */
        inList = file_UniqueCityInList(cityList, city);

        /* If the city is not in the list, append it */
        if(!inList){
            newCity = file_UniqueCityConstructor(city);

            cityList = file_UniqueCityAppend(cityList, newCity);
        }

        inList = 0;
    }

    return cityList;
}

/* Returns true if a City name already exists within the UniqueCityList */
int file_UniqueCityInList(file_UniqueCityList* cityList, char city[CITY_CHAR_SIZE]){
    int inList = 0;

    while(cityList){
        if(strcmp(cityList->cityName, city) == 0){
            inList = 1;
        }

        cityList = cityList->next;
    }

    return inList;
}

/* Based on whether the UniqueCityList is empty or not, attaches another linked list UniqueCity on the end
    of the main linked list chain */
file_UniqueCityList* file_UniqueCityAppend(file_UniqueCityList* cityList, file_UniqueCityList* newCity){
    file_UniqueCityList* temp;

    if(cityList == NULL){
        cityList = newCity;
    } else {
        /* If the list is not empty, traverses to the end and appends the node */
        temp = cityList;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newCity;
    }

    return cityList;
}

/* Constructs and returns a pointer to a linked list node for a UniqueCity */
file_UniqueCityList* file_UniqueCityConstructor(char city[CITY_CHAR_SIZE]){
    file_UniqueCityList* cityLink = malloc(sizeof(file_UniqueCityList));

    strcpy(cityLink->cityName, city);
    cityLink->next = NULL;

    return cityLink;
}

/* Outputs all of the cities that are stored within the UniqueCityList in text format */
void file_UniqueCityOutput(file_UniqueCityList* cityList){
    int index = 0;

    while(cityList){
        printf("%d: %s \n", index, cityList->cityName);
        index++;
        cityList = cityList->next;
    }
}

/* Returns the corresponding index of a city using the list by comparing at which index
    the string it located */
int file_UniqueCityIndex(char city[CITY_CHAR_SIZE], file_UniqueCityList* cityList){
    int index = 0;

    if(cityList == NULL){
        return -1;
    }

    while(strcmp(cityList->cityName, city) != 0){
        index++;
        cityList = cityList->next;
    }

    return index;
}

/* Returns the number of cities that are stored */
int file_UniqueCityCount(file_UniqueCityList* cityList){
    int count = 0;

    while(cityList){
        count++;
        cityList = cityList->next;
    }

    return count;
}

/* Based on an index, outputs the corresponding city's name,
    (ideally should return a char*, redundant due to other function)*/
void file_UniqueCityOutputCity(int index, file_UniqueCityList* cityList){
    int count = 0;

    while(count != index){
        count++;
        cityList = cityList->next;
    }

    printf(" %s ", cityList->cityName);
}

/* Based on an index, outputs the corresponding city's name */
char* file_UniqueCityIndexToCity(int index, file_UniqueCityList* cityList){
    int count = 0;

    while(count != index){
        count++;
        cityList = cityList->next;
    }

    return cityList->cityName;
}

/* -------------------- Pair List -------------------- */

/* Parses the included citypairs text file and creates a linked list of all of the
    pairs the will be used as tests for the pathing algorithm */
file_PairList* file_GeneratePairList(file_UniqueCityList* cityList){
    FILE* file;

    file_PairList* pairList = NULL;
    file_PairList* newPair;

    char start[CITY_CHAR_SIZE], destination[CITY_CHAR_SIZE];
    int startIndex, destinationIndex;

    if((file = fopen("citypairs.txt", "r")) == NULL){
        printf("File not found.");
        exit(1);
    }

    rewind(file);

    while(fscanf(file, "%s %s", start, destination) != EOF){
        startIndex = file_UniqueCityIndex(start, cityList);
        destinationIndex = file_UniqueCityIndex(destination, cityList);

        newPair = file_PairListConstructor(startIndex, destinationIndex);

        pairList = file_PairListAppend(pairList, newPair);
    }

    return pairList;
}
/* Constructs and returns a pointer to a linked list node for a PairList */
file_PairList* file_PairListConstructor(int start, int destination){
    file_PairList* pairLink = malloc(sizeof(file_PairList));

    pairLink->pairSource = start;
    pairLink->pairDestination = destination;
    pairLink->next = NULL;

    return pairLink;
}

/* Based on whether the PairList is empty or not, attaches another PairList on the end
    of the main linked list chain */
file_PairList* file_PairListAppend(file_PairList* pairList, file_PairList* newPair){
    file_PairList* temp;

    if(pairList == NULL){
        pairList = newPair;
    } else {
        /* If the list is not empty, traverses to the end and appends the node */
        temp = pairList;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newPair;
    }

    return pairList;
}

/* Outputs all of the pairs that are stored in index form */
void file_PairListOutput(file_PairList* pairList){
    while(pairList){
        printf("Path: %d -> %d \n", pairList->pairSource, pairList->pairDestination);
        pairList = pairList->next;
    }
}

/* Outputs the number of pairs that exist in the PairList */
int file_PairListGetNofPairs(file_PairList* pairList){
    int count = 0;

    while(pairList){
        count++;
        pairList = pairList->next;
    }

    return count;
}

/* Retrieves a specific source city index from the list */
int file_PairListGetSource(int index, file_PairList* pairList){
    int count = 0;

    while(count != index){
        count++;
        pairList = pairList->next;
    }

    return pairList->pairSource;
}

/* Retrieves a specific destination city index from the list */
int file_PairListGetDestination(int index, file_PairList* pairList){
    int count = 0;

    while(count != index){
        count++;
        pairList = pairList->next;
    }

    return pairList->pairDestination;
}


