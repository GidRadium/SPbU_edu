#include "qsort.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getMostCommon(const int *array, const size_t size) {
    if (size == 0) {
        return 0;
    }

    int *arrayCopy = malloc(size * sizeof(int));
    for (size_t i = 0; i < size; i++) {
        arrayCopy[i] = array[i];
    }

    qSort(arrayCopy, size);

    int mostCommonValue = arrayCopy[0];
    int mostCommonCount = 1;
    int lastValue = arrayCopy[0];
    int lastCount = 1;
    for (size_t i = 0; i + 1 < size; i++) {
        if (arrayCopy[i] == arrayCopy[i + 1]) {
            lastCount++;
        } else {
            lastValue = arrayCopy[i + 1];
            lastCount = 1;
        }

        if (mostCommonCount < lastCount) {
            mostCommonCount = lastCount;
            mostCommonValue = lastValue;
        }
    }

    free(arrayCopy);

    return mostCommonValue;
}

bool testCorrectness() {
    bool testsCompleted = true;

    const size_t testsCount = 5;
    const size_t testsSize = 10;
    const array[5][10] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
        {4, 3, 5, 1, 2, 3, 4, 5, 6, 1},
        {1, 2, 3, 0, 0, 0, 0, 1, 1, 1},
        {0, 2, 5, 1, 3, 100, 100, 101, 10, 10},
        {-100, -100, 0, 0, 0, 0, 10, 10, 10, 1}
    };

    const resultsArray[5] = {0, 1, 0, 10, 0};

    for (size_t i = 0; i < testsCount; i++) {
        if (resultsArray[i] != getMostCommon(array[i], testsSize)) {
            testsCompleted = false;
        }
    }

    return testsCompleted;
}

int main(void) {
    if (!testCorrectness()) {
        printf("ERROR! Tests failed.\n");
        return -1;
    }

    printf("Tests completed!\n");

    int size = 0;
    while (true) {
        printf("Enter array size: ");
        scanf("%d", &size);
        if (size > 0) {
            break;
        }

        printf("ERROR! Array size should be more than 0.\n");
    }

    int *array = calloc((size_t)size, sizeof(int));
    if (array == NULL) {
        printf("ERROR! Can't allocate memory.\n");
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Most common element is %d.\n", getMostCommon(array, (size_t)size));

    free(array);

    return 0;
}