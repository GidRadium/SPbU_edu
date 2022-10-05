#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swapIntegers(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void strangeSort(int *array, const size_t size) {
    if (size <= 1) {
        return;
    }

    for (size_t firstUnsorted = 0; firstUnsorted < size; firstUnsorted += 2) {
        size_t elementToSwapWith = firstUnsorted;
        for (size_t i = firstUnsorted; i < size; i += 2) {
            if (array[i] < array[elementToSwapWith]) {
                elementToSwapWith = i;
            }
        }

        if (firstUnsorted != elementToSwapWith) {
            swapIntegers(&array[firstUnsorted], &array[elementToSwapWith]);
        }
    }
}

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

        strangeSort(array, size);

        for (size_t i = 0; i + 2 < size; i += 2) {
            if (array[i] > array[i + 2]) {
                testsCompleted = false;
                printf("Error in test %d: %d > %d\n", (int)seedIndex, array[i], array[i + 2]);
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

    strangeSort(array, (size_t)arraySize);

    printf("Strange-sorted array:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}