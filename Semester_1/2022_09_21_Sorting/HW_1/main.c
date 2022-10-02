#include "qsort.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool testCorrectness() {
    const unsigned int seeds[10] = {0, 1, 2, 213123, 123123, 436578, 787878, 5656454, 567878, 254646};
    const size_t seedsSize = 10;
    bool testsCompleted = true;

    for (size_t seedIndex = 0; seedIndex < seedsSize; seedIndex++) {
        srand(seeds[seedIndex]);
        const size_t size = rand();
        int *array = calloc(size, sizeof(int));
        for (size_t i = 0; i < size; i++) {
            array[i] = rand();
        }

        qSort(array, size);

        for (size_t i = 0; i + 1 < size; i++) {
            if (array[i] > array[i + 1]) {
                testsCompleted = false;
                printf("Error in test %d: %d > %d", (int)seedIndex, array[i], array[i + 1]);
            }
        }

        free(array);
    }

    return testsCompleted;
}

int main(void) {
    if (!testCorrectness()) {
        printf("Tests failed\n");
        return -1;
    }

    printf("Tests completed!\n");

    int arraySize = 0;
    while (true) {
        printf("Enter array size: ");
        scanf("%d", &arraySize);
        if (arraySize > 0) {
            break;
        }
        printf("ERROR! Array size should be more than 0.\n");
    }

    printf("Enter array:\n");
    int *array = calloc(arraySize, sizeof(int));
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", &array[i]);
    }

    qSort(array, arraySize);

    printf("Sorted array:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}