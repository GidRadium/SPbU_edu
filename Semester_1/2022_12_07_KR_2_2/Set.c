#include "Set.h"
#include <stdlib.h>

typedef struct Set {
    int value;
    int rank;
    Set *left;
    Set *right;
    Set *parent;
} Set;

Set *createSet(int value) {
    Set *set = malloc(sizeof(Set));
    *set = (Set){value, 0, NULL, NULL, set};
    return set;
}

Set *getParent(Set *set) {
    if (set == NULL) {
        return NULL;
    }

    while (set != set->parent) {
        set = set->parent;
    }

    return set;
}

Set *unite(Set *set1, Set *set2) {
    if (set1 == NULL) {
        return set2;
    }

    if (set2 == NULL) {
        return set1;
    }

    Set *set1Parent = getParent(set1);
    Set *set2Parent = getParent(set2);

    if (set1Parent->rank > set2Parent->rank)


    int *array = getAsArray(set2->treap);
    for (size_t i = 0; i < getSize(set2->treap); i++) {
        insert(set1->treap, array[i]);
    }



}

bool isTheSameSet(Set *set1, Set *set2);

void freeSet(Set *set);
