#include "qSort.h"

#include <stdio.h>

int *readUnlimitedArrayFromFile(const char *fileName, size_t *readedArraySize) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("ERROR! File not found.\n");
        return NULL;
    }

    size_t size = 1;
    size_t lastEmpty = 0;
    int *array = malloc(size * sizeof(int));
    int temp = 0;

    while (!feof(file)) {
        fscanf(file, "%d", &temp);

        if (lastEmpty == size) {
            size *= 2;
            int* tempArray = malloc(size * sizeof(int));
            for (size_t i = 0; i < lastEmpty; i++) {
                tempArray[i] = array[i];
            }

            free(array);
            array = tempArray;
        }

        array[lastEmpty] = temp;
        lastEmpty++;
    }

    fclose(file);

    int *finallyArray = malloc(lastEmpty * sizeof(int));
    for (size_t i = 0; i < lastEmpty; i++) {
        finallyArray[i] = array[i];
    }

    free(array);

    *readedArraySize = lastEmpty;
    return finallyArray;
}

int main(void) {
    size_t size = 0;
    int *array = readUnlimitedArrayFromFile("../../input.txt", &size);
    if (array == NULL) {
        return -1;
    }

    printf("Array:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    qSort(array, size);

    printf("\nSorted:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}