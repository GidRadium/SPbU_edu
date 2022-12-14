#pragma once

#include <stdlib.h>

// Stored element type
typedef char * DequeElement;

// Main struct of Deque
typedef struct Deque Deque;

// Allocates mem for Deque. Returns NULL if something goes wrong
Deque *createDeque();

// Deletes Deque struct
void deleteDeque(Deque *deque);

// Clears all elements and frees memory
void clear(Deque *const deque);

// Pushes DequeElement to the front of the Deque. Allways allocates memory
void pushFront(Deque *const deque, DequeElement element);

// Pushes DequeElement to the back of the Deque. Allways allocates memory
void pushBack(Deque *const deque, DequeElement element);

// Deletes first DequeElement
void popFront(Deque *const deque);

// Deletes last DequeElement
void popBack(Deque *const deque);

// Returns first DequeElement
DequeElement getFront(Deque *const deque);

// Returns last DequeElement
DequeElement getBack(Deque *const deque);

// Returns count of Deque elements
size_t getSize(Deque *const deque);

// New function for task_2
void setMoreAChars(Deque *deque);
