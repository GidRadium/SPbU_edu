#include "Stack.h"
#include <stdio.h>

int main(void) {
    int errorCode = 0;
    Stack *stack = createStack(&errorCode);
    if (errorCode) printf("ERROR! Code %d.", errorCode);
    errorCode = 0;

    push(stack, 10, &errorCode);

    if (errorCode) printf("ERROR! Code %d.", errorCode);
    errorCode = 0;
    printf("%d\n", getTop(stack, &errorCode));
    if (errorCode) printf("ERROR! Code %d.", errorCode);
    errorCode = 0;

    pop(stack, &errorCode);

    if (errorCode) printf("ERROR! Code %d.", errorCode);
    errorCode = 0;
    printf("%d\n", getTop(stack, &errorCode));
    if (errorCode) printf("ERROR! Code %d.", errorCode);
    errorCode = 0;

    deleteStack(stack, &errorCode);
    
    if (errorCode) printf("ERROR! Code %d.", errorCode);
    errorCode = 0;
}
