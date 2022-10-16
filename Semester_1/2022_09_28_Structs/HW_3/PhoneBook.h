#pragma once

#include <stdlib.h>

// comment
typedef struct PhoneBookEntry {
    long long phoneNumber;
    char name[100];
} PhoneBookEntry;

// comment
typedef struct PhoneBook {
    PhoneBookEntry entries[100];
    size_t count;
} PhoneBook;

// comment
void initNewPhoneBook(PhoneBook *phoneBook);

// comment
void readPhoneBookFromFile(PhoneBook *phoneBook);

// 1
void addEntryToPhoneBook(PhoneBook *phoneBook, PhoneBookEntry entry);

// 2
void printAllPhoneBookEntries(PhoneBook *phoneBook);

// 3
PhoneBookEntry findEntryByName(PhoneBook *phoneBook, char name[100]);

// 4
PhoneBookEntry findEntryByPhoneNumber(PhoneBook *phoneBook, long long phoneNumber);

// 5
void savePhoneBookToFile(PhoneBook *phoneBook);

// lol
void getPhoneNumberFromString(char *string);