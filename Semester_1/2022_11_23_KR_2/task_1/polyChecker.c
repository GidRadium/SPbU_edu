#include "polyChecker.h"
#include "Deque.h"

#include <stdio.h>

bool isPolyndrom(const char *filePath, int* errorCode) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        if (errorCode != NULL) {
            *errorCode = -2;
        }

        return false;
    }

    Deque* deque = createDeque();
    if (deque == NULL) {
        if (errorCode != NULL) {
            *errorCode = -1;
        }

        return false;
    }

    int temp = 0;

    while (!feof(file)) {
        fscanf(file, "%d", &temp);
        pushBack(deque, temp);
    }

    fclose(file);

    bool answer = true;

    for (int i = getSize(deque); i > 1; i--) {
        if (getFront(deque) != getBack(deque)) {
            answer = false;
            break;
        }

        popFront(deque);
        popBack(deque);
    }

    deleteDeque(deque);

    return answer;
}
