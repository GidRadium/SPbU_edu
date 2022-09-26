#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

struct CorrectTest {
    size_t size;
    int *array;
    int *result;
};

void swapInts(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

// function 0
void bubbleSort(int *array, size_t size) {
    if (size < 2) {
        return;
    }

    while (true) {
        bool isSorted = true;
        for (size_t i = 0; i + 1 < size; i++) {
            if (array[i] > array[i + 1]) {
                swapInts(&array[i], &array[i + 1]);
                isSorted = 0;
            }
        }

        if (isSorted) {
            break;
        }
    }
}

// function 1
void countingSort(int *array, size_t size) {
    if (size < 2) {
        return;
    }

    int min = INT_MAX;
    int max = INT_MIN;
    for (size_t i = 0; i < size; i++) {
        min = (min > array[i] ? array[i] : min);
        max = (max < array[i] ? array[i] : max);
    }

    size_t delta = max - min;
    if (delta == 0) {
        return;
    }

    int *mask = calloc(delta + 1, sizeof(int));

    for (size_t i = 0; i < size; i++) {
        mask[array[i] - min]++;
    }

    size_t lastEmpty = 0;
    for (size_t i = 0; i <= delta; i++) {
        while (mask[i] > 0) {
            mask[i]--;
            array[lastEmpty] = i + min;
            lastEmpty++;
        }
    }

    free(mask);
}

bool testCorrectness(int functionNumber) {

    struct CorrectTest tests[6];
    size_t testsSize = 6;

    tests[0] = (struct CorrectTest){5, (int[5]){0, 1, 2, 3, 4}, (int[5]){0, 1, 2, 3, 4}};
    tests[1] = (struct CorrectTest){5, (int[5]){4, 3, 2, 1, 1}, (int[5]){0, 1, 2, 3, 4}};
    tests[2] = (struct CorrectTest){5, (int[5]){1, 3, 0, 2, 4}, (int[5]){0, 1, 2, 3, 4}};
    tests[3] = (struct CorrectTest){5, (int[5]){0, 0, 0, 0, 0}, (int[5]){0, 0, 0, 0, 0}};
    tests[4] = (struct CorrectTest){1, (int[1]){-1000000}, (int[1]){-1000000}};
    tests[5] = (struct CorrectTest){5, (int[5]){0, -5, 5, -10, 10}, (int[5]){-10, -5, 0, 5, 10}};

    bool testsComleted = true;
    for (int i = 0; i < testsSize; i++) {
        if (functionNumber == 0) {
            bubbleSort(tests[i].array, tests[i].size);
        } else {
            countingSort(tests[i].array, tests[i].size);
        }
        
        bool testComleted = true;
        for (int j = 0; j < tests[i].size; j++) {
            if (tests[i].array[j] != tests[i].result[j]) {
                testComleted = false;
                testsComleted = false;
            }
        }

        if (!testComleted) {
            printf("ERROR! Function %d. Test %d. Not passed:\n", functionNumber, i);
            for (int j = 0; j < tests[i].size; j++) {
                printf("%d ", tests[i].array[j]);
            }

            printf("\n");
            for (int j = 0; j < tests[i].size; j++) {
                printf("%d ", tests[i].result[j]);
            }

            printf("\n");
        }
    }

    return testsComleted;
}

int main(void) {
    bool testsCompleted = testCorrectness(0);
    testsCompleted &= testCorrectness(1);
    if (!testsCompleted) {
        return -1;
    }

    printf("Tests completed!\n");
}