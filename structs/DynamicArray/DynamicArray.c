#include "DynamicArray.h"

#include <stdlib.h>

typedef struct DynamicArray {
    DynamicArrayElement *array;
    size_t dataSize;
    size_t preallocatedSize;
} DynamicArray;

DynamicArray *createDynamicArray() {
    DynamicArray *dArray = malloc(sizeof(DynamicArray));
    if (dArray == NULL) {
        return NULL;
    }

    *dArray = (DynamicArray){NULL, 0, 0};

    return dArray;
}

void deleteDynamicArray(DynamicArray *dArray) {
    if (dArray == NULL) {
        return;
    }

    if (dArray->array != NULL) {
        free(dArray->array);
    }

    free(dArray);
}

void clear(DynamicArray *dArray) {
    if (dArray == NULL) {
        return;
    }

    if (dArray->array != NULL) {
        free(dArray->array);
    }

    *dArray = (DynamicArray){NULL, 0, 0};
}

DynamicArrayElement get(DynamicArray *const dArray, int index) {
    if (dArray == NULL || dArray->dataSize == 0) {
        return 0;
    }

    index %= (int)dArray->dataSize;
    if (index < 0) {
        index += (int)dArray->dataSize;
    }

    return dArray->array[index];
}

void set(DynamicArray *const dArray, int index, DynamicArrayElement element) {
    if (dArray == NULL || dArray->dataSize == 0) {
        return;
    }

    index %= (int)dArray->dataSize;
    if (index < 0) {
        index += (int)dArray->dataSize;
    }

    dArray->array[index] = element;
}

void pushBack(DynamicArray *const dArray, DynamicArrayElement element) {
    if (dArray == NULL) {
        return;
    }

    if (dArray->dataSize == dArray->preallocatedSize) {
        size_t newPreallocatedSize = dArray->dataSize * 2;
        if (newPreallocatedSize == 0) {
            newPreallocatedSize = 1;
        }

        DynamicArrayElement *newArray = malloc(sizeof(DynamicArrayElement) * newPreallocatedSize);

        for (size_t i = 0; i < dArray->dataSize; i++) {
            newArray[i] = dArray->array[i];
        }

        if (dArray->array != NULL) {
            free(dArray->array);
        }

        dArray->array = newArray;
        dArray->preallocatedSize = newPreallocatedSize;
    }

    dArray->array[dArray->dataSize] = element;
    dArray->dataSize++;
}

void popBack(DynamicArray *const dArray) {
    if (dArray == NULL || dArray->dataSize == 0) {
        return;
    }

    dArray->dataSize--;

    if (dArray->dataSize * 4 < dArray->preallocatedSize) {
        if (dArray->dataSize == 0) {
            free(dArray->array);
            dArray->array = NULL;
            dArray->preallocatedSize = 0;
            return;
        }

        size_t newPreallocatedSize = dArray->dataSize * 2;

        DynamicArrayElement *newArray = malloc(sizeof(DynamicArrayElement) * newPreallocatedSize);

        for (size_t i = 0; i < dArray->dataSize; i++) {
            newArray[i] = dArray->array[i];
        }

        free(dArray->array);

        dArray->array = newArray;
        dArray->preallocatedSize = newPreallocatedSize;
    }
}

size_t getSize(DynamicArray *const dArray) {
    if (dArray == NULL) {
        return 0;
    }

    return dArray->dataSize;
}