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

    set(hashTable, (HashTableKey){"kek"}, 434);
    result &= (get(hashTable, (HashTableKey){"lol"}) == 101);
    result &= (get(hashTable, (HashTableKey){"kek"}) == 434);

    set(hashTable, (HashTableKey){"lol"}, 9999);
    result &= (get(hashTable, (HashTableKey){"lol"}) == 9999);
    result &= (get(hashTable, (HashTableKey){"kek"}) == 434);

    deleteEntry(hashTable, (HashTableKey){"kek"});
    result &= (get(hashTable, (HashTableKey){"lol"}) == 9999);
    result &= (get(hashTable, (HashTableKey){"kek"}) == 0);

    deleteEntry(hashTable, (HashTableKey){"lol"});
    result &= (get(hashTable, (HashTableKey){"lol"}) == 0);
    result &= (get(hashTable, (HashTableKey){"kek"}) == 0);

    deleteHashTable(&hashTable);
    
    if (result == 1) {
        printf("Done!\n");
        return 1;
    } else {
        printf("ERROR!\n");
        return -1;
    }
}
