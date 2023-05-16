#pragma once

typedef struct GameOfLife GameOfLife;

GameOfLife *createGameOfLife(int height, int weight, int **data);

void deleteGameOfLife(GameOfLife **game);

void nextFrame(GameOfLife *game);

void printGameOfLife(GameOfLife *game);
