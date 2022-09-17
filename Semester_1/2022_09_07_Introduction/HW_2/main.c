#include <stdio.h>
#include <stdlib.h>

size_t countZeros(int *array, size_t arraySize) {
    size_t counter = 0;
    for (size_t i = 0; i < arraySize; i++) {
        if (array[i] == 0) {
            counter++;
        }
    }

    return counter;
}

int main(void) {
    printf("Enter array size: ");
    int arraySize = 0;
    scanf("%d", &arraySize);
    if (arraySize < 0) {
        printf("ERROR! Array size can't be less than 0.\n");
        return -1;
    }

    printf("Enter array:\n");
    int *array = malloc(sizeof(int) * arraySize);
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", &array[i]);
    }

    printf("Count of zeros: %d", countZeros(array, (size_t)arraySize));

    free(array);

    return 0;
}