#pragma once

#include <stdlib.h>
#include <stdbool.h>

// Stored keys type
typedef int TreapKey;

// Main struct of Treap
typedef struct Treap Treap;

// Allocates mem for Treap. Returns NULL if something goes wrong
Treap *createTreap();

// Deletes Treap struct
void deleteTreap(Treap *treap);

// Clears all nodes and frees memory
void clear(Treap *treap);

// Adds node by key to Treap
void insert(Treap *treap, TreapKey key);

// Erases node by key from Treap
void erase(Treap *treap, TreapKey key);

// Counts nodes by key (can return only 0 or 1)
size_t count(Treap *treap, TreapKey key);

// Returns min key
TreapKey getBegin(Treap *treap);

// Returns max key
TreapKey getEnd(Treap *treap);

// Returns count of stored keys
size_t getSize(Treap *treap);

// Returns true if size == 0
bool isEmpty(Treap *treap);

// Returns allocated memory with sorted keys
TreapKey *getAsArray(Treap *treap);
