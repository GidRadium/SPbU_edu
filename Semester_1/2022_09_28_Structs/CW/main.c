#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct DequeNode {
    int value;
    struct DequeNode *prev;
    struct DequeNode *next;
} DequeNode;

typedef struct Deque {
    size_t size;
    struct DequeNode *begin;
    struct DequeNode *end;
} Deque;

bool pushBack(Deque *deque, int value) {
    DequeNode *node = malloc(sizeof(DequeNode));
    *node = (DequeNode){value, NULL, NULL};
    if (node == NULL) {
        return false;
    }

    if (deque->size == 0) {
        deque->size = 1;
        deque->begin = node;
        deque->end = node;
    } else {
        deque->size++;
        // if (deque->end == NULL) ERROR
        deque->end->next = node;
        node->prev = deque->end;
        deque->end = node;
    }

    return true;
}

bool pushFront(Deque *deque, int value) {
    DequeNode *node = malloc(sizeof(DequeNode));
    *node = (DequeNode){value, NULL, NULL};
    if (node == NULL) {
        return false;
    }

    if (deque->size == 0) {
        deque->size = 1;
        deque->begin = node;
        deque->end = node;
    } else {
        deque->size++;
        // if (deque->begin == NULL) ERROR
        deque->begin->prev = node;
        node->next = deque->begin;
        deque->begin = node;
    }
}

bool popBack(Deque *deque) {
    if (deque->size == 0) {
        return false;
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
}

bool popFront(Deque *deque) {
    if (deque->size == 0) {
        return false;
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
}

int main() {
    Deque deque = (Deque){0, NULL, NULL};
    pushBack(&deque, 1);
    pushBack(&deque, 2);
    pushBack(&deque, 3);
    pushBack(&deque, 4);

    for (DequeNode *node = deque.begin; true; node = node->next) {
        printf("%d, ", node->value); if (node == deque.end) break;}
    printf("\n");
    
    pushFront(&deque, 0);

    for (DequeNode *node = deque.begin; true; node = node->next) {
        printf("%d, ", node->value); if (node == deque.end) break;}
    printf("\n");

    popBack(&deque);

    for (DequeNode *node = deque.begin; true; node = node->next) {
        printf("%d, ", node->value); if (node == deque.end) break;}
    printf("\n");

    popFront(&deque);

    for (DequeNode *node = deque.begin; true; node = node->next) {
        printf("%d, ", node->value); if (node == deque.end) break;}
    printf("\n");

}