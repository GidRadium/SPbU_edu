#pragma once

#pragma once

#include <stdlib.h>

// Data, that AVLtree contains
typedef int AVLtreeValue;

// Node of the AVLtree
typedef struct AVLtreeNode AVLtreeNode;

// User interface struct
typedef struct AVLtree AVLtree;

// Function that allocates memory for AVLtree
AVLtree* createAVLtree(int *errorCode);

// Function that frees memory from AVLtree
void deleteAVLtree(AVLtree *avlTree, int *errorCode);

// Function that pops all Stack elements
void clearAVLtree(AVLtree *avlTree, int *errorCode);

// Function that adds new element to the top of the Stack
void insert(AVLtree *avlTree, AVLtreeValue value, int *errorCode);

// Function that pops element from the top of the Stack
void erase(VLtree *avlTree, AVLtreeValue value, int *errorCode);

// Function that returns top element from Stack
//StackValue getTop(Stack *stack, int *errorCode);

// Function that returns count of elements in Stack
//size_t getSize(Stack *stack, int *errorCode);