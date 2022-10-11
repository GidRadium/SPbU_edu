#include "BinInt.h"

#include <stdio.h>

BinInt toBinInt(int value) {
    BinInt binInt;
    for (int i = 0; i < 32; i++) {
        binInt.data[i] = value & 1;
        value = value >> 1;
    }

    return binInt;
}

int fromBinInt(BinInt binInt) {
    int result = 0;
    for (int i = 0; i < 31; i++) {
        result += (binInt.data[i] ? (1 << i) : 0);
    }

    if (binInt.data[31]) {
        result = (int)((long long)result - (1ll << 31));
    }

    return result;
}

void printBinInt(BinInt binInt) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (int)binInt.data[i]);
    }
}

BinInt summBinInts(BinInt a, BinInt b) {
    int temp = 0;
    for (int i = 0; i < 32; i++) {
        temp += a.data[i] + b.data[i];
        a.data[i] = temp & 1;
        temp = temp >> 1;
    }

    return a;
}