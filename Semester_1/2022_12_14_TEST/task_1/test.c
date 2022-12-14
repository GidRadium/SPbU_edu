#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "getIntStr.h"

// Returns 0 (false) if correct
bool checkCorrectness(char *input, char *output) {
    char *result = getIntStr(input);
    if (result == NULL) {
        return 1;
    }

    bool answer = strcmp(result, output);
    free(result);
    return answer;
}

int main(void) {

    if (checkCorrectness("0", "0")) {
        printf("ERROR! %s != %s\n", "0", "0");
        return -1;
    }

    if (checkCorrectness("1", "1")) {
        printf("ERROR! %s != %s\n", "1", "1");
        return -1;
    }

    if (checkCorrectness("101010", "42")) {
        printf("ERROR! %s != %s\n", "101010", "42");
        return -1;
    }

    if (checkCorrectness("11111", "31")) {
        printf("ERROR! %s != %s\n", "11111", "31");
        return -1;
    }

    printf("Tests completed!\n");

    return 0;
}
