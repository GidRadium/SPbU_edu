#include "Treap.h"

#include <stdio.h>

int main(void) {
    Treap *treap = createTreap();

    printf("Testing insert & getSize & getEnd... ");
    for (int i = 0; i < 100; i++) {
        insert(treap, i);
        if (getSize(treap) != (size_t)(i + 1) || getEnd(treap) != i) {
            printf("ERROR!\n");
            return -1;
        }
    }

    printf("Done!\n");

    printf("Testing erase & getSize & getBegin... ");
    for (int i = 0; i < 50; i++) {
        erase(treap, i);
        if (getSize(treap) != (size_t)(100 - i - 1) || getBegin(treap) != i + 1) {
            printf("%d != %d\n", (int)getSize(treap), (100 - i - 1));
            printf("ERROR!\n");
            return -1;
        }
    }

    printf("Done!\n");

    deleteTreap(treap);

    return 0;
}
