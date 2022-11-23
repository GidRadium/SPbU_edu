#pragma once

#include <stdlib.h>

typedef int TreapKey;

typedef struct Treap Treap;

Treap *createTreap();

void deleteTreap(Treap *treap);

void clear(Treap *treap);

void insert(Treap *treap, TreapKey key);

void erase(Treap *treap, TreapKey key);

size_t count(Treap *treap, TreapKey key);

TreapKey begin(Treap *treap);

TreapKey end(Treap *treap);

bool isEmpty(Treap *treap);
