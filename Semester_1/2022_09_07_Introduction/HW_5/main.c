#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isBracketSequenceCorrect(char* bracketSequence) {
    size_t bracketSequenceSize = strlen(bracketSequence) - 1;
    int counter = 0;

    for (size_t i = 0; i < bracketSequenceSize; i++) {
        if (bracketSequence[i] == '(') {
            counter++;
        } else if (bracketSequence[i] == ')') {
            counter--;
        } else {
            return false;
        }
        
        if (counter < 0) {
            return false;
        }
    }

    return counter == 0;
}

char* scanString() {
    size_t size = 2;
    size_t lastEmpty = 0;
    char* inputString = calloc(size, sizeof(char));
    bool done = false;
    
    while (true) {
        for (; lastEmpty + 1 < size; lastEmpty++) {
            scanf("%c", &inputString[lastEmpty]);
            if (inputString[lastEmpty] == '\n') {
                done = true;
                break;
            }
        }

        if (done) {
            return inputString;
        }

        size *= 2;
        char* tempString = inputString;
        inputString = calloc(size, sizeof(char));
        for (size_t i = 0; i < lastEmpty; i++) {
            inputString[i] = tempString[i];
        }

        free(tempString);
    }
}

int main(void) {

    char* bracketSequence = NULL;
    while (true) {
        printf("Enter bracket sequence:\n");
        bracketSequence = scanString();
        if (strlen(bracketSequence) - 1 != 0) {
            break;
        }

        printf("ERROR! String is empty.\n");
        free(bracketSequence);
    }
    
    printf(isBracketSequenceCorrect(bracketSequence) 
        ? "Bracket sequence is correct!\n" 
        : "Bracket sequence is NOT correct!\n");

    free(bracketSequence);

    return 0;
}