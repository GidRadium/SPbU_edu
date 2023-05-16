#pragma once

#include <stdlib.h>

// PhoneBookEntry struct.
typedef struct PhoneBookEntry PhoneBookEntry;

// PhoneBookEntry constructor.
PhoneBookEntry *createPhoneBookEntry(const char *name, const char *phoneNumber);

// PhoneBookEntry destructor.
void deletePhoneBookEntry(PhoneBookEntry **entry);

// Prints PhoneBookEntry in parsed form
void printPhoneBookEntry(PhoneBookEntry *entry);

// PhoneBook struct.
typedef struct PhoneBook PhoneBook;

// PhoneBook constructor.
PhoneBook *createPhoneBook(const char *filename);

// PhoneBook destructor.
void deletePhoneBook(PhoneBook **phoneBook);

// 1
void addEntryToPhoneBook(PhoneBook *phoneBook, PhoneBookEntry* entry);

// 2
void printAllPhoneBookEntries(PhoneBook *phoneBook);

// 3
PhoneBookEntry *findEntryByName(PhoneBook *phoneBook, const char *name);

// 4
PhoneBookEntry *findEntryByPhoneNumber(PhoneBook *phoneBook, const char *phoneNumber);

// 5
void savePhoneBook(PhoneBook *phoneBook);
