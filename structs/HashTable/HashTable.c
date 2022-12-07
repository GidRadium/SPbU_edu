#include "HashTable.h"
#include "DynamicArrayStrInt.h"

typedef struct HashTable {
    size_t size;
    DynamicArray **array;
};

size_t getHash(HashTableKey key, size_t hashSize) {
    size_t result = 0;
    for (size_t i = 0; key[i] != '\0'; i++) {
        result = (result + key[i]) % hashSize;
    }

    return result;
}

HashTable *createHashTable() {
    HashTable *hashTable = malloc(sizeof(HashTable));
    hashTable->size = 10;
    hashTable->array = malloc(hashTable->size * sizeof(DynamicArray *));
    for (size_t i = 0; i < hashTable->size; i++) {
        hashTable->array[i] = createDynamicArray();
    }

    return hashTable;
}
