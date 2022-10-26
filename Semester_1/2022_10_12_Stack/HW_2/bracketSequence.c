#include "bracketSequence.h"
#include <string.h>

char getOpposite(char bracket) {
    if (bracket == '(') {
        return ')';
    } else if (bracket == ')') {
        return '(';
    } else if (bracket == '[') {
        return ']';
    } else if (bracket == ']') {
        return '[';
    } else if (bracket == '}') {
        return '{';
    } else if (bracket == '{') {
        return '}';
    }

    return '\0';
}

bool checkBracketSequenceCorrectness(char *bracketSequence, int *errorCode) {
    int stackErrorCode = 0;
    size_t size = strlen(bracketSequence);
    
    Stack *stack = createStack(&stackErrorCode);
    if (stackErrorCode != 0) {
        if (errorCode != NULL) {
            *errorCode = stackErrorCode;
        }

        return false;
    }

    bool result = true;
    char bracket = '\0';

    for (size_t i = 0; i < size; i++) {
        bracket = bracketSequence[i];
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            push(stack, (int)bracket, &stackErrorCode);
        } else if(bracket == ')' || bracket == ']' || bracket == '}') {
            if (getSize(stack, NULL) == 0) {
                result = false;
                break;
            }

            if (getOpposite(bracket) == (char)getTop(stack, NULL)) {
                pop(stack, &stackErrorCode);
            } else {
                result = false;
                break;
            }
        } else {
            result = false;
            break;
        }

        if (stackErrorCode != 0) {
            result = false;
            if (errorCode != NULL) {
                *errorCode = stackErrorCode;
            }

            break;
        }
    }

    if (stackErrorCode == 0) {
        if (getSize(stack, NULL) != 0) {
            result = false;
        }

        deleteStack(stack, &stackErrorCode);
    }

    return result;
}
