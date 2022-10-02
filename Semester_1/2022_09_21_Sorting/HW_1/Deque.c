#include "deque.h"

bool pushBack(Deque *deque, int value) {
    DequeNode *node = malloc(sizeof(DequeNode));
    if (node == NULL) {
        return true;
    }

    *node = (DequeNode){value, NULL, NULL};
    
    if (deque->size == 0) {
        deque->size = 1;
        deque->begin = node;
        deque->end = node;
    } else {
        if (deque->end == NULL) {
            return true;
        }

        deque->size++;
        deque->end->next = node;
        node->prev = deque->end;
        deque->end = node;
    }

    return false;
}

bool pushFront(Deque *deque, int value) {
    DequeNode *node = malloc(sizeof(DequeNode));
    if (node == NULL) {
        return true;
    }

    *node = (DequeNode){value, NULL, NULL};
    
    if (deque->size == 0) {
        deque->size = 1;
        deque->begin = node;
        deque->end = node;
    } else {
        if (deque->begin == NULL) {
            return true;
        }

        deque->size++;
        deque->begin->prev = node;
        node->next = deque->begin;
        deque->begin = node;
    }

    return false;
}

bool popBack(Deque *deque) {
    if (deque->size == 0) {
        return true;
    }

    if (deque->size == 1) {
        free(deque->end);
        *deque = (Deque){0, NULL, NULL};
    } else {
        DequeNode *node = deque->end;
        deque->end = deque->end->prev;
        deque->end->next = NULL;
        deque->size--;
        free(node);
    }

    return false;
}

bool popFront(Deque *deque) {
    if (deque->size == 0) {
        return true;
    }

    if (deque->size == 1) {
        free(deque->begin);
        *deque = (Deque){0, NULL, NULL};
    } else {
        DequeNode *node = deque->begin;
        deque->begin = deque->begin->next;
        deque->begin->prev = NULL;
        deque->size--;
        free(node);
    }

    return false;
}