#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

size_t countNumberOfOccurrences(char* firstString, char* secondString) {
    size_t firstStringSize = strlen(firstString) - 1;
    size_t secondStringSize = strlen(secondString) - 1;
    size_t counter = 0;
    for (size_t i = 0; i < firstStringSize; i++) {
        size_t tempCounter = 0;
        for (size_t j = 0; j < secondStringSize; j++) {
            if (i + j < firstStringSize && firstString[i + j] == secondString[j]) {
                tempCounter++;
                if (tempCounter == secondStringSize) {
                    counter++;
                }
            } else {
                break;
            }
        }
    }

    return counter;
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
    char* firstString = NULL;
    while (true) {
        printf("Enter first string:\n");
        firstString = scanString();
        if (strlen(firstString) - 1 != 0) {
            break;
        }

        printf("ERROR! String is empty.\n");
        free(firstString);
    }

    char* secondString = NULL;
    while (true) {
        printf("Enter second string:\n");
        secondString = scanString();
        if (strlen(secondString) - 1 != 0) {
            break;
        }

        printf("ERROR! String is empty.\n");
        free(secondString);
    }

    printf("The number of occurrences of first string in second is: %d\n", 
        countNumberOfOccurrences(firstString, secondString));
    
    free(firstString);
    free(secondString);

    return 0;
}