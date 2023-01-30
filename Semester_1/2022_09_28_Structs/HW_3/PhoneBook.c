#include "PhoneBook.h"

typedef struct PhoneBookEntry {
    char *phoneNumber;
    char *name;
} PhoneBookEntry;

typedef struct PhoneBook {
    PhoneBookEntry entries[100];
    size_t numberOfEntries;
    char *filename;
} PhoneBook;


