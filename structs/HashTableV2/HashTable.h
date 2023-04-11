#pragma once

#include <stdlib.h>

#define MAX_HASH_TABLE_STRING_SIZE 100

// string -> int
typedef struct HashTable HashTable;

// HashTable key struct.
typedef struct HashTableKey {
    char string[MAX_HASH_TABLE_STRING_SIZE];
} HashTableKey;

// Creates HashTable struct.
HashTable *createHashTable();

// Clears allocated mem and sets NULL to hashTable.
void deleteHashTable(HashTable **hashTable);

// Clears all entries.
void clear(HashTable *hashTable);

// Creates or updates entry.
void set(HashTable *hashTable, HashTableKey key, int value);

// Returns entry value. Retuns 0 if it is not created.
int get(HashTable *hashTable, HashTableKey key);

// Deletes entry. Nothing, if it is not exist.
void deleteEntry(HashTable *hashTable, HashTableKey key);
