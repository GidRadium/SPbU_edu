#include "DynamicArray.h"
#include <stdlib.h>

int main(void) {
    DynamicArray *dArray = createDynamicArray();
    if (dArray == NULL) {
        return -1;
    }

    pushBack(dArray, 100);
    if (get(dArray, 0) != 100) {
        return -1;
    }

    if (getSize(dArray) != 1) {
        return -1;
    }

    return 0;
}
