#include <stdio.h>
#include "HashTable.h"

void printTextStats(const char *filePath, int* errorCode) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        if (errorCode != NULL) {
            *errorCode = -2;
        }

        return;
    }

    char temp = 0;

    char text[1000] = {0};

    int index = 0;
    while (!feof(file)) {
        fscanf(file, "%c", &temp);
        text[index] = temp;
        index++;
    }

    fclose(file);

    char word[100] = {0};
    int wordIndex = 0;
    for (int i = 0; i < index; index++) {
        if (text[i] != '\n' && text[i] != ' ') {
            
        }
    }

}

int main(void) {
    
}