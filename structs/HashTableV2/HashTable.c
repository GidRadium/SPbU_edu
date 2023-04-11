#include "HashTable.h"

typedef struct HashTable {
    size_t entriesCount;
    size_t arraySize;
    HashTableValue *array;
} HashTable;

HashTable *createHashTable() {
    HashTable *hashTable = malloc(sizeof(HashTable));
    hashTable->arraySize = 10;
    hashTable->entriesCount = 0;
}

void deleteHashTable(HashTable **hashTable) {
    if (hashTable == NULL) {
        return;
    }

    free(*hashTable);
    *hashTable = NULL;
}
