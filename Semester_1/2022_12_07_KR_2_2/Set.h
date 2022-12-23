#pragma once

#include <stdbool.h>

// Main Set struct
typedef struct Set Set;

// Allocates mem for Set
Set *createSet(int value);

// Merges Sets
Set *unite(Set *set1, Set *set2);

// Checks if set1 and set2 belong to the same set
bool isTheSameSet(Set *set1, Set *set2);

// Frees all set
void freeSet(Set *set);
