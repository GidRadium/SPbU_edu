#include <stdio.h>
#include <stdlib.h>

void swapIntegers(int *a, int *b) {
    *a = (*a ^ *b);
    *b = (*a ^ *b);
    *a = (*a ^ *b);
}

// [from; to)
void reverseSubsegment(int *array, size_t from, size_t to) {
    for (size_t i = 0; i < (to - from) / 2; i++) {
        swapIntegers(&array[from + i], &array[to - i - 1]);
    }
}

void swapSubsegments(int *array, size_t prefixSize, size_t suffixSize) {
    reverseSubsegment(array, 0, prefixSize);
    reverseSubsegment(array, prefixSize, prefixSize + suffixSize);
    reverseSubsegment(array, 0, prefixSize + suffixSize);
}

int main(void) {
    printf("Enter prefix size: ");
    int prefixSize = 0;
    scanf("%d", &prefixSize);
    if (prefixSize < 0) {
        printf("ERROR! Prefix size can't be less than 0!\n");
        return -1;
    }

    printf("Enter suffix size: ");
    int suffixSize = 0;
    scanf("%d", &suffixSize);
    if (suffixSize < 0) {
        printf("ERROR! Suffix size can't be less than 0!\n");
        return -1;
    }
    
    int arraySize = prefixSize + suffixSize;
    printf("Enter array (%d elements):\n", arraySize);
    int *array = malloc((size_t)arraySize * sizeof(int));
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", &array[i]);
    }

    swapSubsegments(array, (size_t)prefixSize, (size_t)suffixSize);

    printf("Swaped array:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }

    free(array);

    printf("\n");

    return 0;
}