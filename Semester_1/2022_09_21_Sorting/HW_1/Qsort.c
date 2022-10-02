#include "qsort.h"
#include "deque.h"

void swapInts(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

bool qSort(int *array, size_t size) {
    if (size <= 1) {
        return false;
    }

    Deque leftBorderStack = (Deque){0, NULL, NULL};
    Deque rightBorderStack = (Deque){0, NULL, NULL};

    pushBack(&leftBorderStack, 0);
    pushBack(&rightBorderStack, size);
    
    while (leftBorderStack.size > 0) {
        const size_t left = leftBorderStack.end->value;
        popBack(&leftBorderStack);
        const size_t right = rightBorderStack.end->value;
        popBack(&rightBorderStack);
        const size_t segmentSize = right - left;

        if (segmentSize <= 1) {
            continue;
        }

        if (segmentSize < 10) {
            for (size_t i = left + 1; i < right; i++) {
                for (size_t j = i; j > left && array[j - 1] > array[j]; j--) {
                    swapInts(&array[j], &array[j - 1]);
                }
            }

            continue;
        }

        const int pivot = array[left + rand() % segmentSize];
        size_t first = left;
        size_t last = right - 1;
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

        pushBack(&leftBorderStack, left);
        pushBack(&rightBorderStack, first);
        pushBack(&leftBorderStack, first);
        pushBack(&rightBorderStack, right);
    }

    return false;
}