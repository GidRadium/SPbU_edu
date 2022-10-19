#include "Stack.h"

typedef struct StackElement {
    StackValue value;
    StackElement *next;
} StackElement;

typedef struct Stack {
    StackElement* head;
    size_t size;
} Stack;

Stack* createStack(int *errorCode) {
    Stack* stack = malloc(sizeof(stack));
    if (stack == NULL) {
        if (errorCode != NULL) {
            *errorCode = -1;
        }

        return NULL;
    }

    stack->size = 0;
    stack->head = NULL;

    return stack;
}

void deleteStack(Stack *stack, int *errorCode) {
    if (stack == NULL) {
        if (errorCode != NULL) {
            *errorCode = 1;
        }

        return;
    }

    // TODO
}

void clearStack(Stack *stack, int *errorCode) {
    if (stack == NULL) {
        if (errorCode != NULL) {
            *errorCode = 1;
        }

        return;
    }

    // TODO
}

void push(Stack* stack, StackValue value, int *errorCode) {
    if (stack == NULL) {
        if (errorCode != NULL) {
            *errorCode = 1;
        }

        return;
    }

    StackElement *element = malloc(sizeof(StackElement));

    if (element == NULL) {
        if (errorCode != NULL) {
            *errorCode = -1;
        }

        return;
    }

    element->value = value;
    element->next = stack->head;
    stack->head = element;
    stack->size++;
}

void pop(Stack* stack, int *errorCode) {
    if (stack == NULL) {
        if (errorCode != NULL) {
            *errorCode = 1;
        }

        return;
    }

    if (stack->size == 0) {
        if (errorCode != NULL) {
            *errorCode = 2;
        }

        return;
    }

    StackElement *element = stack->head;
    stack->head = stack->head->next;
    
    free(element);
}

StackValue getTop(Stack* stack, int *errorCode) {
    if (stack == NULL) {
        if (errorCode != NULL) {
            *errorCode = 1;
        }

        return 0;
    }

    if (stack->size == 0) {
        if (errorCode != NULL) {
            *errorCode = 2;
        }

        return 0;
    }

    return stack->head->value;
}

size_t getSize(Stack* stack, int *errorCode) {
    return stack->size;
}
