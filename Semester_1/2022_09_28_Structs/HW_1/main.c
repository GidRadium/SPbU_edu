#include <stdio.h>
#include "BinInt.h"

int main(void) {

    printf("Enter first number: ");
    int value1 = 0;
    scanf("%d", &value1);

    printf("Enter second number: ");
    int value2 = 0;
    scanf("%d", &value2);

    printf("First:  ");
    BinInt binValue1 = toBinInt(value1);
    printBinInt(binValue1);
    printf(" = %d\n", fromBinInt(binValue1));

    printf("Second: ");
    BinInt binValue2 = toBinInt(value2);
    printBinInt(binValue2);
    printf(" = %d\n", fromBinInt(binValue2));

    printf("Summ:   ");
    BinInt binSumm = summBinInts(binValue1, binValue2);
    printBinInt(binSumm);
    printf(" = %d\n", fromBinInt(binSumm));
}