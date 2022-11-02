#include "List.h"

typedef struct ListElement {
    ListValue value;
    ListElement *next;
} ListElement;

typedef struct List {
    size_t size;
    ListElement *first;
    ListElement *last;
} List;

List *createList(int *errorCode) {
    if (errorCode != NULL) {
        *errorCode = 0;
    }

    List *list = malloc(sizeof(List));
    if (list == NULL) {
        if (errorCode != NULL) {
            *errorCode = -1;
        }

        return NULL;
    }

    list->size = 0;
    list->first = NULL;
    list->last = NULL;

    return list;
}

void deleteList(List *list, int *errorCode) {

}

void clearList(List *list, int *errorCode) {

}

void pushBack(List *list, ListValue value, int *errorCode) {

}
