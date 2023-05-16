#include <stdio.h>
#include <stdlib.h>
#include "GameOfLife.h"

int main(void) {
    int h = 0;
    int w = 0;
    int k = 0;

    scanf("%d %d %d", &h, &w, &k);

    int **data = calloc(h, sizeof(int*));
    for (int i = 0; i < h; i++) {
        data[i] = calloc(w, sizeof(int));
        for (int j = 0; j < w; j++) {
            char in = '0';
            scanf("%c", &in);
            data[i][j] = (in == '1');
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%d", data[i][j]);
        }
        printf("\n");
    }

    GameOfLife *game = createGameOfLife(h, w, data);
    printGameOfLife(game);
    deleteGameOfLife(&game);
}
