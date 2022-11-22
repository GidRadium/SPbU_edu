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











