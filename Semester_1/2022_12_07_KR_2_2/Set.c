#include "Set.h"
#include <stdlib.h>
#include "DynamicArray.h"

typedef struct Set {
    int value;
    int rank;
    Set *parent;
    DynamicArray *array;
} Set;

Set *createSet(int value) {
    Set *set = malloc(sizeof(Set));
    *set = (Set){value, 0, set, NULL};
    set->array = createDynamicArray();
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

    if (set1Parent == set2Parent) {
        return set1Parent;
    }

    if (set1Parent->rank > set2Parent->rank) {
        pushBack(set1Parent->array, set2Parent);
        set1Parent->rank++;
        set2Parent->parent = set1Parent;
    } else {
        pushBack(set2Parent->array, set1Parent);
        set1Parent->parent = set2Parent;
        set2Parent->rank++;
    }

    return getParent(set1Parent);
}

bool isTheSameSet(Set *set1, Set *set2) {
    return getParent(set1) == getParent(set2);
}

void freeSet(Set *set) {
    if (set == NULL) {
        return;
    }

    for (size_t i = 0; i < getSize(set->array); i++) {
        freeSet(get(set->array, i));
    }

    deleteDynamicArray(set->array);
    free(set);
}
