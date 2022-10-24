#include "Stack.h"
#include <stdio.h>

int main(void) {
    int errorCode = 0;

    Stack *stack = createStack(&errorCode);
    if (errorCode) printf("ERROR! Code %d.", errorCode);

    push(stack, 10, &errorCode);
    if (errorCode) printf("ERROR! Code %d.", errorCode);

    printf("%d\n", getTop(stack, &errorCode));
    if (errorCode) printf("ERROR! Code %d.", errorCode);

    pop(stack, &errorCode);
    if (errorCode) printf("ERROR! Code %d.", errorCode);

    push(stack, 20, &errorCode);
    if (errorCode) printf("ERROR! Code %d.", errorCode);

    printf("%d\n", getTop(stack, &errorCode));
    if (errorCode) printf("ERROR! Code %d.", errorCode);

    deleteStack(stack, &errorCode);
    if (errorCode) printf("ERROR! Code %d.", errorCode);
}
