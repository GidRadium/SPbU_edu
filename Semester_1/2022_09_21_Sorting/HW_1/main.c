#include "qsort.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    srand(182378);
    const size_t size = 100;
    int *array = calloc(size, sizeof(int));

    for (size_t i = 0; i < size; i++) {
        array[i] = rand();
    }

    qSort(array, size);
    for (size_t i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
    
    return 0;
}