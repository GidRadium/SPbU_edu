#include <stdio.h>
#include "Set.h"

int main(void) {
    Set *a = createSet(1);
    Set* b = createSet(2);

    if (isTheSameSet(a, b)) {
        printf("Tests failed!\n");
        return -1;
    }

    Set *c = unite(a, b);

    if (!isTheSameSet(a, b)) {
        printf("Tests failed!\n");
        return -1;
    }

    Set *d = createSet(3);

    if (isTheSameSet(d, a) || isTheSameSet(d, b)) {
        printf("Tests failed!\n");
        return -1;
    }

    Set *e = unite(a, d);

    if (!isTheSameSet(d, a) || !isTheSameSet(d, b) || !isTheSameSet(d, c)) {
        printf("Tests failed!\n");
        return -1;
    }

    printf("Tests passed!\n");

    freeSet(a);

    return 0;
}
