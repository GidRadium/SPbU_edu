#include <stdio.h>
#include <stdlib.h>

#include "countSymbols.h"

int main(void) {
    printf("Enter file path (less than 200 symbols):\n");
    char path[200] = {0};
    scanf("%s", path);

    int array[256] = {0};
    int errorCode = 0;
    countSymbols(array, path, &errorCode);
    if (errorCode == -1) {
        printf("ERROR! Can't open file \"%s\"\n", path);
        return;
    }

    for (size_t i = 0; i < 256; i++) {
        if (array[i] > 0) {
            if (i == '\n') {
                printf("'\\n' (%d): %d\n", i, array[i]);
            } else {
                printf("'%c' (%d): %d\n", (char)i, i, array[i]);
            }
        }
    }

    return 0;
}
