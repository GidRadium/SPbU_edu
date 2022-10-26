#include "countSymbols.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    printf("Enter test.txt file path (include test.txt) (less than 200 symbols):\n");
    char path[200] = {0};
    scanf("%s", path);

    int array[256] = {0};
    int errorCode = 0;
    countSymbols(array, path, &errorCode);
    if (errorCode == -1) {
        printf("ERROR! Can't open file \"%s\"\n", path);
        return;
    }

    int resultArray[256];
    for (size_t i = 0; i < 256; i++) {
        resultArray[i] = 0;
    }

    resultArray['\n'] = 9;
    resultArray[' '] = 6;
    resultArray['!'] = 1;
    resultArray['.'] = 1;
    resultArray['e'] = 6;
    resultArray['q'] = 8;
    resultArray['r'] = 5;
    resultArray['t'] = 4;
    resultArray['w'] = 7;
    resultArray['y'] = 3;

    bool testsCompleted = true;

    for (size_t i = 0; i < 256; i++) {
        if (resultArray[i] != array[i]) {
            testsCompleted = false;
            break;
        }
    }

    if (testsCompleted) {
        printf("Tests completed!\n");
    } else {
        printf("Tests failed!\n");
    }
}
