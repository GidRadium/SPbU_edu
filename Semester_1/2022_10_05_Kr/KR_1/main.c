#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swapIntegers(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int getEvenFibonacciBeforeValue(const int value) {
    int a = 1;
    int b = 1;
    int summ = 0;
    while (b <= value) {
        if (b % 2 == 0) {
            summ += b;
        }

        a += b;
        swapIntegers(&a, &b);
    }

    return summ;
}

bool testCorrectness() {
    bool testsCompleted = true;

    const size_t testsCount = 4;
    int valuesArray[4] = {1, 3, 5, 8};
    int resultsArray[4] = {0, 2, 2, 10};

    for (size_t i = 0; i < testsCount; i++) {
        if (getEvenFibonacciBeforeValue(valuesArray[i]) != resultsArray[i]) {
            testsCompleted = false;
            printf("%d != %d\n", getEvenFibonacciBeforeValue(valuesArray[i]), resultsArray[i]);
        }
    }

    return testsCompleted;
}

int main() {
    if (!testCorrectness()) {
        printf("ERROR! Tests failed.\n");
        return -1;
    }

    printf("Tests completed!\n");
    printf("Even fibonacci summ before 1000000: %d", getEvenFibonacciBeforeValue(1000000));

    return 0;
}