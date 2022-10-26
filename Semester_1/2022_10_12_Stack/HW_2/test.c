#include <stdio.h>
#include "bracketSequence.h"

int main(void) {
    bool result = true;

    result &= (checkBracketSequenceCorrectness("", NULL) == true);
    result &= (checkBracketSequenceCorrectness("", NULL) == true);
    result &= (checkBracketSequenceCorrectness("()()()(){}{}{}{}[][][][][]", NULL) == true);
    result &= (checkBracketSequenceCorrectness("][", NULL) == false);
    result &= (checkBracketSequenceCorrectness("[]()[]()[]{}{}{", NULL) == false);
    result &= (checkBracketSequenceCorrectness("()([{[()]}])({[]})[{}]{[]}", NULL) == true);

    printf(result ? "All tests passed!\n" : "Test failed!\n");

    return (int)result - 1;
}