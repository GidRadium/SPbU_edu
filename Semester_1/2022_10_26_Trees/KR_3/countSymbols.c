#include "countSymbols.h"

#include <stdio.h>
#include <stdlib.h>

void countSymbols(int resultArray[256], const char* filePath, int* errorCode) {
    if (resultArray == NULL) {
        if (errorCode != NULL) {
            *errorCode = 1;
        }

        return;
    }

    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        if (errorCode != NULL) {
            *errorCode = -1;
        }

        return;
    }

    for (size_t i = 0; i < 256; i++) {
        resultArray[i] = 0;
    }

    char tempSymbol = '\0';
    fscanf(file, "%c", &tempSymbol);
    while (!feof(file)) {
        resultArray[tempSymbol]++;
        fscanf(file, "%c", &tempSymbol);
    }

    fclose(file);
}
