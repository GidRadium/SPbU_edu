#include "Deque.h"

typedef struct DequeNode {
    DequeElement element;
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

    *deque = (Deque){0, NULL, NULL};

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

    *deque = (Deque){0, NULL, NULL};
}

void pushFront(Deque *const deque, DequeElement element) {
    if (deque == NULL) {
        return;
    }

    DequeNode *dequeNode = malloc(sizeof(DequeNode));
    *dequeNode = (DequeNode){element, NULL, deque->begin};

    if (deque->begin == NULL) {
        deque->begin = dequeNode;
        deque->end = dequeNode;
    } else {
        deque->begin->prev = dequeNode;
        deque->begin = dequeNode;
    }

    deque->size++;
}

void pushBack(Deque *const deque, DequeElement element) {
    if (deque == NULL) {
        return;
    }

    DequeNode *dequeNode = malloc(sizeof(DequeNode));
    *dequeNode = (DequeNode){element, deque->end, NULL};

    if (deque->end == NULL) {
        deque->begin = dequeNode;
        deque->end = dequeNode;
    } else {
        deque->end->next = dequeNode;
        deque->end = dequeNode;
    }

    deque->size++;
}

void popFront(Deque *const deque) {
    if (deque == NULL || deque->begin == NULL) {
        return;
    }

    DequeNode *dequeNode = deque->begin;
    deque->begin = deque->begin->next;
    if (deque->begin == NULL) {
        deque->end = NULL;
    } else {
        deque->begin->prev = NULL;
    }

    free(dequeNode);

    deque->size--;
}

void popBack(Deque *const deque) {
    if (deque == NULL || deque->end == NULL) {
        return;
    }

    DequeNode *dequeNode = deque->end;
    deque->end = deque->end->prev;
    if (deque->end == NULL) {
        deque->begin = NULL;
    } else {
        deque->end->next = NULL;
    }

    free(dequeNode);

    deque->size--;
}

DequeElement getFront(Deque *const deque) {
    if (deque == NULL || deque->begin == NULL) {
        return 0;
    }

    return deque->begin->element;
}

DequeElement getBack(Deque *const deque) {
    if (deque == NULL || deque->end == NULL) {
        return 0;
    }

    return deque->end->element;
}

size_t getSize(Deque *const deque) {
    if (deque == NULL) {
        return 0;
    }

    return deque->size;
}
