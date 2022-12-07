#pragma once

#include <stdlib.h>

typedef char * HashTableKey;

typedef int HashTableValue;

typedef struct HashTable HashTable;

size_t getHash(HashTableKey key);

HashTable *createHashTable();

void deleteHashTable(HashTable *hashTable);

void clear(HashTable *hashTable);

void set(HashTable *hashTable, HashTableKey key, HashTableValue value);

HashTableValue get(HashTable *hashTable, HashTableKey key);
