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
    if (a != b) {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

// function 0
void bubbleSort(int *array, const size_t size) {
    if (size < 2) {
        return;
    }

    while (true) {
        bool isSorted = true;
        for (size_t i = 0; i + 1 < size; i++) {
            if (array[i] > array[i + 1]) {
                swapInts(&array[i], &array[i + 1]);
                isSorted = false;
            }
        }

        if (isSorted) {
            break;
        }
    }
}

// function 1
void countingSort(int *array, const size_t size) {
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

    int *elementsNumber = calloc(delta + 1, sizeof(int));

    for (size_t i = 0; i < size; i++) {
        elementsNumber[array[i] - min]++;
    }

    size_t lastEmpty = 0;
    for (size_t i = 0; i <= delta; i++) {
        while (elementsNumber[i] > 0) {
            elementsNumber[i]--;
            array[lastEmpty] = i + min;
            lastEmpty++;
        }
    }

    free(elementsNumber);
}

enum FunctionToTest {
    bubbleSortFunc,
    countingSortFunc
};

bool testCorrectness(enum FunctionToTest functionToTest) {

    struct CorrectTest tests[6];
    size_t testsSize = 6;

    tests[0] = (struct CorrectTest){5, (int[5]){0, 1, 2, 3, 4}, (int[5]){0, 1, 2, 3, 4}};
    tests[1] = (struct CorrectTest){5, (int[5]){4, 3, 2, 1, 0}, (int[5]){0, 1, 2, 3, 4}};
    tests[2] = (struct CorrectTest){5, (int[5]){1, 3, 0, 2, 4}, (int[5]){0, 1, 2, 3, 4}};
    tests[3] = (struct CorrectTest){5, (int[5]){0, 0, 0, 0, 0}, (int[5]){0, 0, 0, 0, 0}};
    tests[4] = (struct CorrectTest){1, (int[1]){-1000000}, (int[1]){-1000000}};
    tests[5] = (struct CorrectTest){5, (int[5]){0, -5, 5, -10, 10}, (int[5]){-10, -5, 0, 5, 10}};

    bool testsComleted = true;
    for (int i = 0; i < testsSize; i++) {
        if (functionToTest == bubbleSortFunc) {
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
            printf("ERROR! Function %s. Test %d. Not passed:\n", (functionToTest == bubbleSortFunc ? "bubbleSort" : "countingSort"), i);
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

void compareDuration(void) {
    const size_t arraySize = 100000;
    printf("BubbleSort VS CountingSort on %zu element array:\n", arraySize);
    int *array1 = calloc(arraySize, sizeof(int));
    int *array2 = calloc(arraySize, sizeof(int));

    for (size_t i = 0; i < arraySize; i++) {
        array1[i] = rand() - RAND_MAX / 2;
        array2[i] = array1[i];
    }

    clock_t startBubbleSort = clock();
    bubbleSort(array1, arraySize);
    clock_t stopBubbleSort = clock();

    clock_t startCountingSort = clock();
    countingSort(array2, arraySize);
    clock_t stopCountingSort = clock();

    free(array1);
    free(array2);

    printf("BubbleSort:   %3.3f seconds\n"
        , (double)(stopBubbleSort - startBubbleSort) / CLOCKS_PER_SEC);
    printf("CountingSort: %3.3f seconds\n"
        , (double)(stopCountingSort - startCountingSort) / CLOCKS_PER_SEC);
}

int main(void) {
    bool testsCompleted = testCorrectness(0);
    testsCompleted &= testCorrectness(1);
    if (!testsCompleted) {
        return -1;
    }

    printf("Tests completed!\n");

    compareDuration();

    int arraySize = 0;
    while (arraySize <= 0) {
        printf("Enter array size: ");
        scanf("%d", &arraySize);
        if (arraySize <= 0) {
            printf("ERROR! Array size can't be less than 0.\n");
        }
    }

    printf("Enter array:\n");
    int *array = calloc((size_t)arraySize, sizeof(int));
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", &array[i]);
    }

    bubbleSort(array, (size_t)arraySize);

    printf("Sorted array:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }

    free(array);
}