#ifndef SET_H
#define SET_H

#include <stdbool.h>

typedef struct Set Set;

Set *createSet(int value);

Set *unite(Set *set1, Set *set2);

bool isTheSameSet(Set *set1, Set *set2);

void freeSet(Set *set);

#endif