#include "citiesDistributer.h"
#include "../../../structs/DynamicArray/DynamicArray.h"

size_t *distributeCitiesAmongStates(
    size_t numberOfCities, 
    size_t numberOfRoads, Road *roads, 
    size_t numberOfCapitals, size_t *capitals
) {
    size_t *capitalOf = calloc(numberOfCities, sizeof(size_t));
    for (size_t i = 0; i < numberOfCities; i++) {
        capitalOf[i] = numberOfCities;
    }

    for (size_t i = 0; i < numberOfCapitals; i++) {
        capitalOf[capitals[i]] = capitals[i];
    }

    DynamicArray **connectedVertices = calloc(numberOfCities, sizeof(DynamicArray *));
    for (size_t i = 0; i < numberOfCities; i++) {
        connectedVertices[i] = createDynamicArray();
    }

    for (size_t i = 0; i < numberOfRoads; i++) {
        pushBack(connectedVertices[roads[i].from], roads[i].to);
        pushBack(connectedVertices[roads[i].to], roads[i].from);
    }

    // -_-
}


