#include "BinInt.h"

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int main(void) {
    printf("Testsing...\n");

    bool testsCompleted = true;
    size_t arraySize = 25;
    int array[25] = {
        INT_MIN, INT_MIN / 2, INT_MIN / 4, INT_MIN / 10, INT_MIN / 100,
        INT_MAX, INT_MAX / 2, INT_MAX / 4, INT_MAX / 10, INT_MAX / 100,
        0, 1, 2, 3, 10, 20, 100, 255, -1, -2, -3, -10, -20, -100, -255
    };

    for (size_t i = 0; i < arraySize; i++) {
        if (array[i] != fromBinInt(toBinInt(array[i]))) {
            testsCompleted = false;
            printf("ERROR! Casting failed. %d != %d\n"
                , array[i], fromBinInt(toBinInt(array[i])));
        }
    }

    for (size_t i = 0; i < arraySize; i++) {
        for (size_t j = 0; j < arraySize; j++) {
            int result = fromBinInt(summBinInts(toBinInt(array[i]), toBinInt(array[j])));
            if (array[i] + array[j] != result) {
                testsCompleted = false;
                printf("ERROR! Summing failed. %d != %d\n"
                    , array[i] + array[j], result);
            }
        }
    }

    if (!testsCompleted) {
        printf("ERROR! Some tests failed.\n");
        return -1;
    }

    printf("Success! All tests pased.\n");

    return 0;
}