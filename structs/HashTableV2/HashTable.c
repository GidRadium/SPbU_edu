#include "HashTable.h"
#include <stdbool.h>
#include <string.h>

#define MIN_HASH_TABLE_ARRAY_SIZE 10

size_t getHash(HashTableKey key, size_t hashSize) {
    size_t result = 0;
    for (size_t i = 0; key.string[i] != '\0' && i < MAX_HASH_TABLE_STRING_SIZE; i++) {
        result = (result + key.string[i]) % hashSize;
    }

    return result;
}

bool areEqual(HashTableKey key1, HashTableKey key2) {
    return !strcmp(key1.string, key2.string);
}

typedef enum HashTableEntryFlag {
    IsEmpty = 0,
    ContainsData,
    IsDeleted,
} HashTableEntryFlag;

typedef struct HashTableEntry {
    HashTableEntryFlag flag;
    size_t hash;
    int value;
    HashTableKey key;
} HashTableEntry;

typedef struct HashTable {
    size_t entriesCount;
    size_t arraySize;
    HashTableEntry *array;
} HashTable;

// Returns true if entry is new, and false if entry is overwritten.
bool addEntryToArray(HashTableEntry *entryArray, size_t arraySize, HashTableKey key, int value) {
    size_t hash = getHash(key, arraySize);
    for (size_t i = hash; i < arraySize; i++) {
        if (entryArray[i].flag == IsEmpty || entryArray[i].flag == IsDeleted) {
            entryArray[i] = (HashTableEntry){ContainsData, hash, value, key};
            return true;
        } else if (hash == entryArray[i].hash && areEqual(key, entryArray[i].key)) {
            entryArray[i].value = value;
            return false;
        }

        if (i + 1 >= arraySize) {
            i = 0;
        }
    }

    return false;
}

// Returns true if entry is deleted sucsessfully, and false if entry wasn't exist.
bool deleteEntryFromArray(HashTableEntry *entryArray, size_t arraySize, HashTableKey key) {
    size_t hash = getHash(key, arraySize);
    
    for (size_t i = hash; i < arraySize; i++) {
        if (entryArray[i].flag == IsEmpty) {
            return false;
        } else if (entryArray[i].flag == ContainsData && hash == entryArray[i].hash && areEqual(key, entryArray[i].key)) {
            entryArray[i].flag = IsDeleted;
            return true;
        }

        if (i + 1 >= arraySize) {
            i = 0;
        }
    }

    return false;
}

// Resizes hashTable array.
void reconstructHashTable(HashTable *hashTable) {
    if (hashTable == NULL) {
        return;
    }

    size_t newArraySize 
        = hashTable->entriesCount * 4 < MIN_HASH_TABLE_ARRAY_SIZE
        ? MIN_HASH_TABLE_ARRAY_SIZE
        : hashTable->entriesCount * 4;
    HashTableEntry *newArray = calloc(newArraySize, sizeof(HashTableEntry));

    if (hashTable->array != NULL) {
        for (size_t i = 0; i < hashTable->arraySize; i++) {
            if (hashTable->array[i].flag == ContainsData) {
                addEntryToArray(newArray, newArraySize, hashTable->array[i].key, hashTable->array[i].value);
            }
        }

        free(hashTable->array);
    }
    
    hashTable->array = newArray;
    hashTable->arraySize = newArraySize;
}

HashTable *createHashTable() {
    HashTable *hashTable = malloc(sizeof(HashTable));
    if (hashTable == NULL) {
        return NULL;
    }

    hashTable->entriesCount = 0;
    hashTable->arraySize = 0;
    hashTable->array = NULL;
    reconstructHashTable(hashTable);

    return hashTable;
}

void deleteHashTable(HashTable **hashTable) {
    if (hashTable == NULL) {
        return;
    }

    if ((*hashTable)->array != NULL) {
        free((*hashTable)->array);
    }

    free(*hashTable);
    *hashTable = NULL;
}

void clear(HashTable *hashTable) {
    if (hashTable == NULL) {
        return;
    }

    free(hashTable->array);

    hashTable->arraySize = 0;
    hashTable->entriesCount = 0;
    hashTable->array = NULL;

    reconstructHashTable(hashTable);
}

void set(HashTable *hashTable, HashTableKey key, int value) {
    if (hashTable == NULL) {
        return;
    }

    bool keyIsNew = addEntryToArray(hashTable->array, hashTable->arraySize, key, value);
    if (keyIsNew) {
        hashTable->entriesCount++;
    }

    if (hashTable->entriesCount * 2 >= hashTable->arraySize) {
        reconstructHashTable(hashTable);
    }
}

int get(HashTable *hashTable, HashTableKey key) {
    if (hashTable == NULL) {
        return 0;
    }

    size_t hash = getHash(key, hashTable->arraySize);
    for (size_t i = hash; i < hashTable->arraySize; i++) {
        if (hashTable->array[i].flag == IsEmpty) {
            return 0;
        } else if (hashTable->array[i].flag == ContainsData && hash == hashTable->array[i].hash && areEqual(key, hashTable->array[i].key)) {
            return hashTable->array[i].value;
        }

        if (i + 1 >= hashTable->arraySize) {
            i = 0;
        }
    }

    // Invariant ERROR if is here!
    return 35505;
}

void deleteEntry(HashTable *hashTable, HashTableKey key) {
    if (hashTable == NULL) {
        return;
    }

    bool isDeleted = deleteEntryFromArray(hashTable->array, hashTable->arraySize, key);
    if (isDeleted) {
        hashTable->entriesCount--;
    }

    if (hashTable->arraySize > 10 && hashTable->entriesCount * 8 < hashTable->arraySize) {
        reconstructHashTable(hashTable);
    }
}
