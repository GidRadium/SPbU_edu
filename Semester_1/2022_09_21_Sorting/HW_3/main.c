#include "qsort.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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

    return testsCompleted;
}

int main(void) {
    if (!testCorrectness()) {
        printf("ERROR! Tests failed.\n");
        return -1;
    }

    printf("Tests completed!\n");

    int n = 0;
    while (true) {
        printf("Enter array size: ");
        scanf("%d", &n);
        if (n > 0) {
            break;
        }

        printf("ERROR! Array size should be more than 0.\n");
    }

    int *array = malloc((size_t)n * sizeof(int));
    if (array == NULL) {
        printf("ERROR! Can't allocate memory.\n");
    }

    printf("Most common element is %d.\n", getMostCommon(array, (size_t)n));

    free(array);

    return 0;
}