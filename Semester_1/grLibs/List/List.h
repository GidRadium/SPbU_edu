#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef int ListValue;

typedef struct ListElement ListElement;

typedef struct List List;

List* createList(int *errorCode);

void deleteList(List *list, int *errorCode);

void clearList(List *list, int *errorCode);

void pushBack(List *list, ListValue value, int *errorCode);

void insert(List *list, size_t position, ListValue value, int *errorCode);

void erase(List *list, size_t position, ListValue value, int *errorCode);

ListValue getValue(List *list, size_t position, int *errorCode);

size_t getSize(List* list, int *errorCode);

ListElement* getPointer(List *list, size_t position, int *errorCode);

ListElement* getNext(ListElement* element, int *errorCode);

ListValue getValue(ListElement* element, int *errorCode);

bool isEnd(ListElement* element, int *errorCode);
