#include "qsort.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool isInSortedArray(int *array, size_t size, int value) {
    if (size == 0 || value < array[0] || value > array[size - 1]) {
        return false;
    }

    int left = 0;
    int right = size;
    int midd = 0;
    while (left + 1 < right) {
        midd = (left + right) / 2;
        if (array[midd] <= value) {
            left = midd;
        } else {
            right = midd;
        }
    }

    return value == array[left];
}

bool testCorrectness() {
    bool testsCompleted = true;

    int array[6] = {2839, 3939, 23, 0, -100, 1000};
    int requests[10] = {2839, -1000, 100, -100, 0, 23, 22, 24, 10000, 3940};
    bool answers[10] = {true, false, false, true, true, true, false, false, false, false};

    qSort(array, 6);

    for (int i = 0; i < 10; i++) {
        if (isInSortedArray(array, 6, requests[i]) != answers[i]) {
            testsCompleted = false;
        }
    }

    return testsCompleted;
}

int main(void) {
    if (!testCorrectness()) {
        printf("ERROR! Tests failed.\n");
        return -1;
    }

    printf("Tests completed!\n");

    int n = 0;
    while (true) {
        printf("Enter array size: ");
        scanf("%d", &n);
        if (n > 0) {
            break;
        }
        printf("ERROR! Array size should be more than 0.\n");
    }

    int *numbersArray = malloc((size_t)n * sizeof(int));
    if (numbersArray == NULL) {
        printf("ERROR! Can't allocate memory.\n");
    }

    srand(3489);
    for (int i = 0; i < n; i++) {
        numbersArray[i] = rand();
    }

    printf("Sorting... ");
    qSort(numbersArray, (size_t)n);
    printf("Done!\n");

    int k = 0;
    while (true) {
        printf("Enter number of requests: ");
        scanf("%d", &k);
        if (k > 0) {
            break;
        }
        printf("ERROR! Number of requests should be more than 0.\n");
    }

    int value = 0;
    for (int i = 0; i < k; i++) {
        value = rand();
        if (isInSortedArray(numbersArray, (size_t)n, value)) {
            printf("%d) %d is in the random array\n", i, value);
        }
    }

    free(numbersArray);

    return 0;
}