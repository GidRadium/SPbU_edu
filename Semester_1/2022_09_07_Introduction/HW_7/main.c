#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

size_t countNumberOfOccurrences(char* string, size_t stringSize, char* string1, size_t string1Size) {
    size_t counter = 0;
    for (size_t i = 0; i < stringSize; i++) {
        size_t tempCounter = 0;
        for (size_t j = 0; j < string1Size; j++) {
            if (i + j < stringSize && string[i + j] == string1[j]) {
                tempCounter++;
                if (tempCounter == string1Size){
                    counter++;
                }
            } else {
                break;
            }
        }
    }

    return counter;
}

int main(void) {
    printf("Enter S size: ");
    int stringSize = 0;
    scanf("%d", &stringSize);
    if (stringSize < 0) {
        printf("ERROR! S size can't be less than 0!\n");
        return -1;
    }

    printf("Enter S: ");
    char *string = malloc(((size_t)stringSize + 1) * sizeof(char));
    string[stringSize] = '\0';
    fflush(stdin);
    fgets(string, stringSize + 1, stdin);

    printf("Enter S1 size: ");
    int string1Size = 0;
    scanf("%d", &string1Size);
    if (string1Size < 0) {
        printf("ERROR! S1 size can't be less than 0!\n");
        return -1;
    }

    printf("Enter S1: ");
    char *string1 = malloc(((size_t)string1Size + 1) * sizeof(char));
    string1[string1Size] = '\0';
    fflush(stdin);
    fgets(string1, string1Size + 1, stdin);

    printf("The number of occurrences of S1 in S is: %d\n", 
        countNumberOfOccurrences(string, (size_t)stringSize, string1, (size_t)string1Size));
    
    free(string);
    free(string1);

    return 0;
}