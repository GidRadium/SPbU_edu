#include <stdio.h>
#include "HashTable.h"



int main(void) {
    HashTable* hashTable = createHashTable();
    int value = 0;
    int result = 1;

    printf("Testing set & get & delete... ");
    set(hashTable, (HashTableKey){"lol"}, 101);
    result &= (get(hashTable, (HashTableKey){"lol"}) == 101);
    result &= (get(hashTable, (HashTableKey){"kek"}) == 0);
    printf("%d ", result);
    set(hashTable, (HashTableKey){"kek"}, 434);
    result &= (get(hashTable, (HashTableKey){"lol"}) == 101);
    result &= (get(hashTable, (HashTableKey){"kek"}) == 434);
    printf("%d ", result);
    set(hashTable, (HashTableKey){"lol"}, 9999);
    result &= (get(hashTable, (HashTableKey){"lol"}) == 9999);
    result &= (get(hashTable, (HashTableKey){"kek"}) == 434);
    printf("%d ", result);
    deleteEntry(hashTable, (HashTableKey){"kek"});
    result &= (get(hashTable, (HashTableKey){"lol"}) == 9999);
    result &= (get(hashTable, (HashTableKey){"kek"}) == 0);
    printf("%d ", result);
    deleteEntry(hashTable, (HashTableKey){"lol"});
    result &= (get(hashTable, (HashTableKey){"lol"}) == 0);
    result &= (get(hashTable, (HashTableKey){"kek"}) == 0);
    printf("%d ", result);

    deleteHashTable(&hashTable);
    
    if (result == 1) {
        printf("Done!\n");
        return 1;
    } else {
        printf("ERROR!\n");
        return -1;
    }
}
