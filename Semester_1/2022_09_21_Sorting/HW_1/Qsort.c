#include "Qsort.h"
#include "Deque.h"

void swapInts(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

bool Qsort(int *array, size_t size) {
    if (size <= 1) {
        return false;
    }

    if (size <= 10) {
        for (size_t i = 1; i < size; i++) {
            for (size_t j = i; j > 0 && array[j] > array[j - 1]; j--) {
                swapInts(&array[j], &array[j - 1]);
            }
        }
    }



    return false;
}