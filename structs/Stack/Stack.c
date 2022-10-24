#include "Stack.h"

typedef struct StackElement {
    StackValue value;
    StackElement *next;
} StackElement;

typedef struct Stack {
    StackElement *head;
    size_t size;
} Stack;

Stack *createStack(int *errorCode) {
    if (errorCode != NULL) {
        *errorCode = 0;
    }

    Stack *stack = malloc(sizeof(Stack));
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
    if (errorCode != NULL) {
        *errorCode = 0;
    }

    if (stack == NULL) {
        if (errorCode != NULL) {
            *errorCode = 1;
        }

        return;
    }

    while (stack->size > 0) {
        pop(stack, errorCode);
        if (errorCode != NULL && *errorCode != 0) {
            break;
        }
    }

    free(stack);
}

void clearStack(Stack *stack, int *errorCode) {
    if (errorCode != NULL) {
        *errorCode = 0;
    }

    if (stack == NULL) {
        if (errorCode != NULL) {
            *errorCode = 1;
        }

        return;
    }

    while (stack->size > 0) {
        pop(stack, errorCode);
        if (errorCode != NULL && *errorCode != 0) {
            break;
        }
    }
}

void push(Stack *stack, StackValue value, int *errorCode) {
    if (errorCode != NULL) {
        *errorCode = 0;
    }

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

void pop(Stack *stack, int *errorCode) {
    if (errorCode != NULL) {
        *errorCode = 0;
    }

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
    stack->size--;

    free(element);
}

StackValue getTop(Stack *stack, int *errorCode) {
    if (errorCode != NULL) {
        *errorCode = 0;
    }

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

size_t getSize(Stack *stack, int *errorCode) {
    if (errorCode != NULL) {
        *errorCode = 0;
    }

    return stack->size;
}
