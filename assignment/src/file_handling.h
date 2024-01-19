#ifndef FILE_HANDLING_H_INCLUDED
#define FILE_HANDLING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* file_handling involves a set of functions used to parse the data from the
    included text files into dynamic linked list formats */

#define CITY_CHAR_SIZE 256

/*--------- Opaque Struct definitions ---------*/

typedef struct file_PairList file_PairList;
typedef struct file_UniqueCityList file_UniqueCityList;


/*--------- Public Function definitions ---------*/

/* Unique Cities */
file_UniqueCityList* file_GenerateUniqueCities();
void file_UniqueCityOutput(file_UniqueCityList* cityList);
int file_UniqueCityIndex(char city[CITY_CHAR_SIZE], file_UniqueCityList* cityList);
int file_UniqueCityCount(file_UniqueCityList* cityList);
char* file_UniqueCityIndexToCity(int index, file_UniqueCityList* cityList);
void file_UniqueCityOutputCity(int index, file_UniqueCityList* cityList);

/* Pair List */
file_PairList* file_GeneratePairList(file_UniqueCityList* cityList);
void file_PairListOutput(file_PairList* pairList);
int file_PairListGetNofPairs(file_PairList* pairList);

int file_PairListGetSource(int index, file_PairList* pairList);
int file_PairListGetDestination(int index, file_PairList* pairList);

#endif
