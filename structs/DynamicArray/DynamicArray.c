#include "DynamicArray.h"

#include <stdlib.h>

typedef struct DynamicArray {
    DynamicArrayElement *array;
    size_t dataSize;
    size_t preallocatedSize;
} DynamicArray;


DynamicArray * createDynamicArray() {
    DynamicArray *dArray = malloc(sizeof(DynamicArray));
    if (dArray == NULL) {
        return NULL;
    }

    dArray->dataSize = 0;
    dArray->preallocatedSize = 0;
    dArray->array = NULL;
}

void deleteDynamicArray(DynamicArray *dArray) {

}

DynamicArrayElement get(DynamicArray *dArray, size_t index) {
    return 0;
}

void set(DynamicArray *dArray, int index, DynamicArrayElement element) {

}

void pushBack(DynamicArray *dArray, DynamicArrayElement element) {

}

void popBack(DynamicArray *dArray) {

}
