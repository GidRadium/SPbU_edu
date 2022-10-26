#include <stdio.h>
#include "bracketSequence.h"

int main(void) {
    int errorCode = 0;
    if (checkBracketSequenceCorrectness("()(){}{[]}", &errorCode)) {
        printf("Correct!\n");
    } else {
        printf("Not correct!\n");
    }
}