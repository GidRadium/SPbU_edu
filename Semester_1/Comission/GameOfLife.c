#include "GameOfLife.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct GameOfLife {
    int height;
    int weight;
    int **data;
} GameOfLife;

GameOfLife *createGameOfLife(int height, int weight, int **data) {
    // check data
    GameOfLife *game = malloc(sizeof(GameOfLife));
    game->height = height;
    game->weight = weight;
    game->data = calloc(height, sizeof(int*));
    for (int i = 0; i < height; i++) {
        game->data[i] = calloc(weight, sizeof(int));
        for (int j = 0; j < weight; j++) {
            game->data[i][j] = data[i][j];
        }
    }

    return game;
}

void deleteGameOfLife(GameOfLife **game) {
    if (game == NULL || (*game) == NULL) {
        return;
    }

    for (int i = 0; i < (*game)->height; i++) {
        free((*game)->data[i]);
    }

    free((*game)->data);
    free(*game);
    *game = NULL;
}

void nextFrame(GameOfLife *game) {
    if (game == NULL) {
        return;
    }

    int **newData = calloc(game->height, sizeof(int*));
    for (int i = 0; i < game->height; i++) {
        game->data[i] = calloc(game->weight, sizeof(int));
        for (int j = 0; j < game->weight; j++) {
            int countAlive = 0;
            if (i > 0) countAlive += game->data[i - 1][j];
            if (j > 0) countAlive += game->data[i][j - 1];
            if (i < game->height - 1) countAlive += game->data[i + 1][j];
            if (j < game->weight - 1) countAlive += game->data[i][j + 1];
            if (i > 0 && j > 0) countAlive += game->data[i - 1][j - 1];
            if (i > 0 && j < game->weight - 1) countAlive += game->data[i - 1][j + 1];
            if (i < game->height - 1 && j > 0) countAlive += game->data[i + 1][j - 1];
            if (i < game->height - 1 && j < game->weight - 1) countAlive += game->data[i + 1][j + 1];

            if (game->data[i][j] == 0) {
                newData[i][j] = (countAlive == 3);
            } else {
                newData[i][j] = (countAlive == 2 || countAlive == 3);
            }
        }
    }

    for (int i = 0; i < game->height; i++) {
        for (int j = 0; j < game->weight; j++) {
            game->data[i][j] = newData[i][j];
        }
    }

    for (int i = 0; i < game->height; i++) {
        free(newData[i]);
    }

    free(newData);
}

void printGameOfLife(GameOfLife *game) {
    for (int i = 0; i < game->height; i++) {
        for (int j = 0; j < game->weight; j++) {
            printf("%d", game->data[i][j]);
        }

        printf("\n");
    }
}
