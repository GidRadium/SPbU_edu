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

int main(void) {

}