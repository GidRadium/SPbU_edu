#include "HashTableTypes.h"

size_t getHash(HashTableKey key, size_t hashSize) {
    size_t result = 0;
    for (size_t i = 0; key[i] != '\0'; i++) {
        result = (result + key[i]) % hashSize;
    }

    return result;
}
