#include "getIntStr.h"
#include <stdlib.h>
#include <string.h>

char *getIntStr(char *binString) {
    size_t size = strlen(binString);
    int number = 0;
    int ratio = 1;
    for (int i = (int)size - 1; i >= 0; i--) {
        if (binString[i] != '0' && binString[i] != '1') {
            return NULL;
        }

        number += (binString[i] == '1') * ratio;
        ratio *= 2;
    }

    char *result = calloc(11, sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    itoa(number, result, 10);

    return result;
}
