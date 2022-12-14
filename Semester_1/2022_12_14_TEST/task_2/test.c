#include "Deque.h"
#include <stdio.h>
#include <string.h>

int main(void) {
    Deque *deque = createDeque();

    pushBack(deque, "a");
    pushBack(deque, "b");
    pushBack(deque, "abab");
    pushBack(deque, "baba");
    pushBack(deque, "");

    setMoreAChars(deque);

    if (strcmp(getBack(deque), "abab") || getSize(deque) != 7) {
        printf("ERROR!\n");
        deleteDeque(deque);
        return -1;
    }

    deleteDeque(deque);

    printf("All tests passed!\n");

    return 0;
}
