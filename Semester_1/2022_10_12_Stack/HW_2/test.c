#include <stdio.h>
#include "bracketSequence.h"

int main(void) {
    int errorCode = 0;
    checkBracketSequenceCorrectness("()(){}{[]}", &errorCode);
    printf("%d\n", errorCode);
}