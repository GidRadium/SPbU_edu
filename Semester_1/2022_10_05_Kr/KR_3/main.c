#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printAllCommentsFromFile(const char* path) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("ERROR! File not found!");
        return -1;
    }

    char *data[100] = {0};
    int linesRead = 0;

    while (!feof(file)) {
        char *buffer = malloc(sizeof(char) * 100);
        const int readBytes = fscanf(file, "%s", buffer);
        if (readBytes < 0) {
            break;
        }

        data[linesRead] = buffer;
        linesRead++;
    }

    fclose(file);

    bool writingComment = false;
    for (int line = 0; line < linesRead; line++) {
        for (int symbol = 0; symbol < 99; symbol++) {
            if (symbol == ';') {
                writingComment = true;
            } else if (symbol == '\n' || symbol == '\0') {
                if (writingComment) {
                    printf("\n");
                }

                writingComment = false;
            }

            if (writingComment) {
                printf("%c", data[line][symbol]);
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        if (data[i] != NULL) {
            free(data[i]);
        }
    }
}

int main(void) {
    printf("Enter file path: ");
    char *path = malloc(200 * sizeof(char));
    scanf("%s", path);

    printAllCommentsFromFile(path);

    free(path);

    return 0;
}