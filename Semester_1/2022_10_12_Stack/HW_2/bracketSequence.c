#include "bracketSequence.h"
#include <string.h>

bool checkBracketSequenceCorrectness(char *bracketSequence, int *errorCode) {
    int stackErrorCode = 0;
    size_t size = strlen(bracketSequence);
    
    Stack *stack = createStack(&stackErrorCode);
    if (stackErrorCode != 0) {
        return false;
    }

    char bracket = '\0';
    for (size_t i = 0; i < size; i++) {
        bracket = bracketSequence[i];
        if (bracket == '(') {
            push(stack, '(', &stackErrorCode);
            //if (stackErrorCode)
        }
    }

    return false;
}