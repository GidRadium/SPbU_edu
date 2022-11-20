#include "DynamicArray.h"
#include <stdlib.h>

int main(void) {
    DynamicArray *dArray = createDynamicArray();
    if (dArray == NULL) {
        return -1;
    }

    return 0;
}
