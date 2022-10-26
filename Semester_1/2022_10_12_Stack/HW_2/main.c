#include <stdio.h>
#include "bracketSequence.h"

int main(void) {
    printf("Enter bracket sequence:\n");
    char string[200];
    scanf("%s", string);
    int errorCode = 0;
    bool result = checkBracketSequenceCorrectness(string, &errorCode);
    if (errorCode == 0) {
        printf(result 
            ? "Bracket sequence is correct!\n" 
            : "Bracket sequence is NOT correct!\n");
    } else {
        printf("ERROR! Code %d.", errorCode);
    }

    return 0;
}