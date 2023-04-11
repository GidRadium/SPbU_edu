#include <stdio.h>
#include "HashTable.h"

int main(void) {
    
    HashTable* hashTable = createHashTable();
    int value = 0;

    set(hashTable, (HashTableKey){"lol"}, 101);
    value = get(hashTable, (HashTableKey){"lol"});
    printf("%d\n", value);
    value = get(hashTable, (HashTableKey){"kek"});
    printf("%d\n", value);
    set(hashTable, (HashTableKey){"kek"}, 434);
    value = get(hashTable, (HashTableKey){"lol"});
    printf("%d\n", value);
    value = get(hashTable, (HashTableKey){"kek"});
    printf("%d\n", value);

    return 0;
}
