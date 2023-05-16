#include <stdio.h>
#include <stdlib.h>
#include "GameOfLife.h"

int main(void) {
    int height = 0;
    int weight = 0;
    int iterations = 0;

    scanf("%d %d %d", &height, &weight, &iterations);

    int **data = calloc(height, sizeof(int*));

    for (int i = 0; i < height; i++) {
        data[i] = calloc(weight, sizeof(int));
        for (int j = 0; j < weight; j++) {
            int in = 0;
            scanf("%d", &in);
            printf("%d\n", in);

            data[i][j] = in;
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < weight; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }

    GameOfLife *game = createGameOfLife(height, weight, data);

    for (int i = 0; i < iterations; i++) {
        nextFrame(game);
    }

    printGameOfLife(game);
    deleteGameOfLife(&game);
}
