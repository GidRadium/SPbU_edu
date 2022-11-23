#include "Deque.h"
#include <stdio.h>

int main(void) {
    Deque *deque = createDeque();

    printf("Testing pushBack... ");
    for (int i = 0; i < 100; i++) {
        pushBack(deque, i);
        if (getBack(deque) != i) {
            printf("ERROR!\n");
            return -1;
        }
    }

    printf("Done!\n");

    printf("Testing popBack... ");
    for (int i = 99; i >= 0; i--) {
        if (getBack(deque) != i) {
            printf("ERROR!\n");
            return -1;
        }

        popBack(deque);
    }

    printf("Done!\n");

    printf("All tests passed!\n");

    return 0;
}
