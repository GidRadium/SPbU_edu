#pragma once

#include <stdbool.h>

typedef struct BinInt {
    bool data[32];
} BinInt;

// comment
BinInt toBinInt(int value);

// comment
int fromBinInt(BinInt binInt);

// comment
void printBinInt(BinInt binInt);

// comment
BinInt summBinInts(BinInt a, BinInt b);