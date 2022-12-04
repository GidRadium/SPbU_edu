#include "DynamicArray.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    DynamicArray *dArray = createDynamicArray();
    if (dArray == NULL) {
        return -1;
    }

    printf("Testing pushBack... ");
    for (size_t i = 0; i < 10000; i++) {
        pushBack(dArray, i);
    }

    for (size_t i = 0; i < 10000; i++) {
        if (get(dArray, i) != i) {
            printf("ERROR!\n");
            return -1;
        }
    }

    printf("Done!\n");

    printf("Testing popBack... ");
    for (size_t i = 9999; i >= 1000; i--) {
        if (get(dArray, -1) != i) {
            printf("ERROR!\n");
            return -1;
        }

        popBack(dArray, i);
    }

    printf("Done!\n");

    printf("Testing getSize... ");
    if (getSize(dArray) != 1000) {
        printf("ERROR!\n");
        return -1;
    }

    printf("Done!\n");

    deleteDynamicArray(dArray);

    printf("All tests passed!\n");

    return 0;
}
