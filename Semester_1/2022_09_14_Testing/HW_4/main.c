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

int main(void) {

}