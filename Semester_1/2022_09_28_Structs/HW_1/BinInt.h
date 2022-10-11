#pragma once

#include <stdbool.h>

typedef struct BinInt {
    bool data[32];
} BinInt;

// Function, that converts int to BinInt.
BinInt toBinInt(int value);

// Function, that converts BinInt to int.
int fromBinInt(BinInt binInt);

// Function, that prints BinInt as 32 zeros and ones.
void printBinInt(BinInt binInt);

// Function, that adds two BinInt numbers.
BinInt summBinInts(BinInt a, BinInt b);