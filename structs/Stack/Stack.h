#pragma once

#include <stdlib.h>

// Data, that Stack contains
typedef int StackValue;

// Node of the Stack
typedef struct StackElement StackElement;

// User interface struct
typedef struct Stack Stack;

// Function that allocates memory for Stack
Stack *createStack(int *errorCode);

// Function that frees memory from Stack
void deleteStack(Stack *stack, int *errorCode);

// Function that pops all Stack elements
void clearStack(Stack *stack, int *errorCode);

// Function that adds new element to the top of the Stack
void push(Stack *stack, StackValue value, int *errorCode);

// Function that pops element from the top of the Stack
void pop(Stack *stack, int *errorCode);

// Function that returns top element from Stack
StackValue getTop(Stack *stack, int *errorCode);

// Function that returns count of elements in Stack
size_t getSize(Stack *stack, int *errorCode);
