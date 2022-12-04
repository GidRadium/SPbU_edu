#pragma once

#include "HashTableTypes.h"

typedef struct HashTable HashTable;



HashTable *createHashTable();

void deleteHashTable(HashTable *hashTable);

void clear(HashTable *hashTable);


