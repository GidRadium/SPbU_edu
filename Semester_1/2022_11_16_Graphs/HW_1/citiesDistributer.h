#pragma once

#include <stdlib.h>

typedef struct Road {
    size_t from;
    size_t to;
    int length;
} Road;

// returns array of size_t, where array[i] = capital of i-th city
size_t *distributeCitiesAmongStates(
    size_t numberOfCities, 
    size_t numberOfRoads, Road *roads, 
    size_t numberOfCapitals, size_t *capitals
);
