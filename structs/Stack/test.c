#include "Stack.h"
#include <stdio.h>

int main(void) {
    int errorCode = 0;

    Stack *stack = createStack(&errorCode);
    if (errorCode) printf("ERROR! Code %d.\n", errorCode);

    push(stack, 10, &errorCode);
    if (errorCode) printf("ERROR! Code %d.\n", errorCode);

    printf("%d\n", getTop(stack, &errorCode));
    if (errorCode) printf("ERROR! Code %d.\n", errorCode);

    pop(stack, &errorCode);
    if (errorCode) printf("ERROR! Code %d.\n", errorCode);

    push(stack, 20, &errorCode);
    if (errorCode) printf("ERROR! Code %d.\n", errorCode);

    printf("%d\n", getTop(stack, &errorCode));
    if (errorCode) printf("ERROR! Code %d.\n", errorCode);

    clearStack(stack, &errorCode);
    if (errorCode) printf("ERROR! Code %d.\n", errorCode);

    printf("%d\n", getTop(stack, &errorCode));
    if (errorCode) printf("ERROR! Code %d.\n", errorCode);
    // error = all working as should

    push(stack, 30, &errorCode);
    if (errorCode) printf("ERROR! Code %d.\n", errorCode);

    printf("%d\n", getTop(stack, &errorCode));
    if (errorCode) printf("ERROR! Code %d.\n", errorCode);

    deleteStack(stack, &errorCode);
    if (errorCode) printf("ERROR! Code %d.\n", errorCode);
}
