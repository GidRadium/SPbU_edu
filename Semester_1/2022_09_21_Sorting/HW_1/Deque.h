#pragma once

#include <stdlib.h>
#include <stdbool.h>

// node of deque
typedef struct DequeNode {
    int value;
    struct DequeNode *prev;
    struct DequeNode *next;
} DequeNode;

// user interface for Deque Nodes
typedef struct Deque {
    size_t size;
    struct DequeNode *begin;
    struct DequeNode *end;
} Deque;

// Function, that adds new value to the end of Deque. Returns true, if something goes wrong.
bool pushBack(Deque *deque, int value);

// Function, that adds new value to the begin of Deque. Returns true, if something goes wrong.
bool pushFront(Deque *deque, int value);

// Function, that deletes new value fron the end of Deque. Returns true, if something goes wrong.
bool popBack(Deque *deque);

// Function, that deletes new value fron the begin of Deque. Returns true, if something goes wrong.
bool popFront(Deque *deque);

// Function, that sets start parameters to Deque
bool initDeque(Deque *deque);