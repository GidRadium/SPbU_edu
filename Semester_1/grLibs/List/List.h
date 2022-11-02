#pragma once

// For size_t
#include <stdlib.h>

// For bool
#include <stdbool.h>

// Data type
typedef int ListValue;

// List nodes
typedef struct ListElement ListElement;

// Main struct
typedef struct List List;

// List init function
List *createList(int *errorCode);

// List destruction function
void deleteList(List *list, int *errorCode);

void clearList(List *list, int *errorCode);

void pushBack(List *list, ListValue value, int *errorCode);

void insert(List *list, size_t position, ListValue value, int *errorCode);

void erase(List *list, size_t position, ListValue value, int *errorCode);

ListValue getValue(List *list, size_t position, int *errorCode);

size_t getSize(List *list, int *errorCode);

ListElement *getPointer(List *list, size_t position, int *errorCode);

ListElement *getNext(ListElement *element, int *errorCode);

ListValue getValue(ListElement *element, int *errorCode);

bool isEnd(ListElement *element, int *errorCode);
