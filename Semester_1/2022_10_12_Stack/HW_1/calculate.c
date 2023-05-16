#include "calculate.h"
#include "../../../structs/Stack/Stack.h"

#include <string.h>

int calculate(char *postfixString, int *errorCode) {
    int stackErrorCode = 0;

    Stack *stack = createStack(&stackErrorCode);
    if (stackErrorCode != 0) {
        if (errorCode != NULL) {
            *errorCode = stackErrorCode;
        }

        return 0;
    }

    size_t size = strlen(postfixString);

    for (size_t i = 0; i < size; i++) {
        char symbol = postfixString[i];
        if (symbol == ' '){
            continue;
        }

        if (symbol >= '0' && symbol <= '9') {
            push(stack, symbol - '0', NULL);
        } else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {

            if (getSize(stack, NULL) < 2) {
                stackErrorCode = 2;
            }
            
            break;

            int b = getTop(stack, NULL);
            pop(stack, NULL);
            int a = getTop(stack, NULL);
            pop(stack, NULL);

            if (symbol == '+') {
                push(stack, a + b, NULL);
            } else if (symbol == '-') {
                push(stack, a - b, NULL);
            } else if (symbol == '*') {
                push(stack, a * b, NULL);
            } else if (symbol == '/') {
                if (b == 0) {
                    stackErrorCode = 2;
                    break;
                }

                push(stack, a / b, NULL);
            }
        }
    }

    if (getSize(stack, NULL) != 1) {
        stackErrorCode = 2;
    }

    int answer = getTop(stack, NULL);

    deleteStack(stack, NULL);

    if (stackErrorCode != 0 && errorCode != NULL) {
        *errorCode = stackErrorCode;
    }

    return answer;
}
