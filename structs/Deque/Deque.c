#include "Deque.h"

typedef struct DequeNode {
    DequeElement value;
    struct DequeNode *prev;
    struct DequeNode *next;
} DequeNode;

typedef struct Deque {
    size_t size;
    DequeNode *begin;
    DequeNode *end;
} Deque;

Deque *createDeque() {
    Deque *deque = malloc(sizeof(Deque));
    if (deque == NULL) {
        return NULL;
    }

    deque->size = 0;
    deque->begin = NULL;
    deque->end = NULL;

    return deque;
}

void deleteDeque(Deque *deque) {
    if (deque == NULL) {
        return;
    }

    DequeNode *tempNode = deque->begin;
    while (tempNode != NULL) {
        deque->begin = deque->begin->next;
        free(tempNode);
        tempNode = deque->begin;
    }

    free(deque);
    deque = NULL;
}

void clear(Deque *const deque) {
    if (deque == NULL) {
        return;
    }

    DequeNode *tempNode = deque->begin;
    while (tempNode != NULL) {
        deque->begin = deque->begin->next;
        free(tempNode);
        tempNode = deque->begin;
    }

    deque->size = 0;
    deque->end = NULL;
}









