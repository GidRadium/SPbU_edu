#pragma once

#include <stdlib.h>

// comment
typedef int StackValue;

// comment
typedef struct StackElement StackElement;

// comment
typedef struct Stack Stack;

// comment
Stack* createStack(int *errorCode);

// comment
void deleteStack(Stack *stack, int *errorCode);

// comment
void clearStack(Stack *stack, int *errorCode);

// comment
void push(Stack* stack, StackValue value, int *errorCode);

// comment
void pop(Stack* stack, int *errorCode);

// comment
StackValue getTop(Stack* stack, int *errorCode);

// comment
size_t getSize(Stack* stack, int *errorCode);
