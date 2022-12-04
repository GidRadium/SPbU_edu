#pragma once

#include <stdlib.h>

typedef char * HashTableKey;

typedef int HashTableValue;

size_t getHash(HashTableKey key);
