#include "Deque.h"
#include <stdio.h>

int main(void) {
    Deque *deque = createDeque();

    printf("Testing pushBack... ");
    for (int i = 0; i < 10000; i++) {
        pushBack(deque, i);
        if (getBack(deque) != i) {
            printf("ERROR!\n");
            return -1;
        }
    }

    printf("Done!\n");

    printf("Testing popBack... ");
    for (int i = 9999; i >= 0; i--) {
        if (getBack(deque) != i) {
            printf("ERROR!\n");
            return -1;
        }

        popBack(deque);
    }

    printf("Done!\n");

    printf("Testing pushFront... ");
    for (int i = 0; i < 10000; i++) {
        pushFront(deque, i);
        if (getFront(deque) != i) {
            printf("ERROR!\n");
            return -1;
        }
    }

    printf("Done!\n");

    printf("Testing popFront... ");
    for (int i = 9999; i >= 0; i--) {
        if (getFront(deque) != i) {
            printf("ERROR!\n");
            return -1;
        }

        popFront(deque);
    }

    printf("Done!\n");

    printf("Testing getSize... ");
    if (getSize(deque) != 0) {
        printf("ERROR!\n");
        return -1;
    }

    pushBack(deque, 1928347);

    if (getSize(deque) != 1) {
        printf("ERROR!\n");
        return -1;
    }

    printf("Done!\n");

    printf("All tests passed!\n");

    return 0;
}
