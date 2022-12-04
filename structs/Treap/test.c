#include "Treap.h"

#include <stdio.h>

void printTreap(Treap *treap) {
    int *array = getAsArray(treap);
    for (size_t i = 0; i < getSize(treap); i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
    free(array);
}

int main(void) {
    Treap *treap = createTreap();

    printf("Testing insert & getSize & getEnd... ");
    for (int i = 0; i < 10; i++) {
        insert(treap, i);
        if (getSize(treap) != (size_t)(i + 1) || getEnd(treap) != i) {
            printf("ERROR!\n");
            return -1;
        }
    }

    printf("Done!\n");

    printf("Testing erase & getSize & getBegin... ");
    for (int i = 0; i < 5; i++) {
        erase(treap, i);
        if (getSize(treap) != (size_t)(10 - i - 1) || getBegin(treap) != i + 1) {
            printf("ERROR!\n");
            return -1;
        }
    }

    printf("Done!\n");

    deleteTreap(treap);

    return 0;
}
