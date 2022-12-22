#include "polyChecker.h"

#include <stdio.h>

int main(void) {
    printf("Enter file path (less than 200 symbols):\n");
    char path[200] = {0};
    scanf("%s", path);

    int errorCode = 0;

    if (isPolyndrom(path, &errorCode)) {
        printf("Array is polindrom!\n");
    } else {
        if (errorCode == -1) {
            printf("Memory allocation error!\n");
            return -1;
        } else if(errorCode == -2) {
            printf("File not found!\n");
            return -1;
        } else {
            printf("Array is NOT polindrom!\n");
        }
    }

    return 0;
}
