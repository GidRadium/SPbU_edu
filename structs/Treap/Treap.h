#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef int TreapKey;

typedef struct Treap Treap;

Treap *createTreap();

void deleteTreap(Treap *treap);

void clear(Treap *treap);

void insert(Treap *treap, TreapKey key);

void erase(Treap *treap, TreapKey key);

size_t count(Treap *treap, TreapKey key);

TreapKey getBegin(Treap *treap);

TreapKey getEnd(Treap *treap);

size_t getSize(Treap *treap);

bool isEmpty(Treap *treap);

TreapKey *getAsArray(Treap *treap);

