#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

void swapInts(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void halfOfQsort(int *array, const size_t size) {
    if (size <= 1) {
        return;
    }

    const int pivot = array[0];
    size_t first = 0;
    size_t last = size - 1;
    while (first < last) {
        if (array[first] < pivot) {
            first++;
            continue;
        }

        if (array[last] >= pivot) {
            last--;
            continue;
        }

        swapInts(&array[first], &array[last]);
    }
}

bool testCorrectness(void) {
    bool testsCompleted = true;
    const size_t testCount = 1000;

    for (size_t testNumber = 0; testNumber < testCount; testNumber++) {
        const size_t size = rand();
        int *array = calloc(size, sizeof(int));
        for (size_t i = 0; i < size; i++) {
            array[i] = rand() - RAND_MAX / 2;
        }

        const int pivot = array[0];
        halfOfQsort(array, size);
        size_t changeCounter = 0;
        for (int i = 0; i + 1 < size; i++) {
            changeCounter += array[i] < pivot && array[i + 1] >= pivot;
        }

        if (changeCounter > 1) {
            testsCompleted = false;
            printf("ERROR! Test %d not passed.\n", testNumber);
        }
    }

    return testsCompleted;
}

int main(void) {
    srand(time(0));
    if (!testCorrectness()) {
        return -1;
    }

    printf("Tests completed!\n");

    const size_t size = 10;
    int *array = calloc(size, sizeof(int));
    for (size_t i = 0; i < size; i++) {
        array[i] = rand();
    }

    printf("Before halfOfQsort():\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    halfOfQsort(array, size);

    printf("After halfOfQsort():\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
}