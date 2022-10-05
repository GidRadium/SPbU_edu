#include <stdio.h>
#include <stdlib.h>

int writeFromFile() {
    FILE* out = fopen("ololo.txt", "w");
    if (out == NULL) {
        return -1;
    }
    fwrite("Ololo\n", sizeof(char), 6, out);
    fprintf(out, "%s", "Ololo");
    fclose(out);
    return 0;
}

int readFromFile() {
    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("file not found!");
        return 1;
    }

    char *data[100] = {0};
    int linesRead = 0;
    char *buffer = malloc(sizeof(char) * 100);
    while (!feof(file)) {
        const int readBytes = fscanf(file, "%s", buffer);
        if (readBytes < 0) {
        break;
        }
        data[linesRead] = buffer;
        ++linesRead;
    }

    free(buffer);

    fclose(file);
}

int main() {
    return 0;
}