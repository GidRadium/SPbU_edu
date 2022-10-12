#include "qSort.h"

#include <stdio.h>
#include <stdbool.h>

bool testQSortCorrectness() {
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
    bool testsCompleted = true;

    printf("Testsing qSort() correctness...\n");
    bool qSortTestFeedback = testQSortCorrectness();
    printf("%s\n", qSortTestFeedback ? "Success!" : "Failed!");
    testsCompleted &= qSortTestFeedback;

    // Space for more tests

    if (!testsCompleted) {
        printf("ERROR! Some tests failed.\n");

        return -1;
    }

    printf("Success! All tests have been passed.\n");

    return 0;
}