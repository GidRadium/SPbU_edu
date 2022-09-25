#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void swapInts(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void bubbleSort(int* array, size_t size) {
    if (size < 2) {
        return;
    }

    while (true) {
        bool isSorted = 1;
        for (int i = 0; i + 1 < size; i++) {
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





int main() {

}