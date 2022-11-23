#pragma once

#include <stdlib.h>

typedef int DequeElement;

typedef struct Deque Deque;

Deque *createDeque();

void deleteDeque(Deque *deque);

void clear(Deque *const deque);

void pushFront(Deque *const deque, DequeElement element);

void pushBack(Deque *const deque, DequeElement element);

void popFront(Deque *const deque);

void popBack(Deque *const deque);

DequeElement getFront(Deque *const deque);

DequeElement getBack(Deque *const deque);

size_t getSize(Deque *const deque);
