#include "BinInt.h"

#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "");

    printf("Введите первое число: ");
    int value1 = 0;
    scanf("%d", &value1);

    printf("Введите второе число: ");
    int value2 = 0;
    scanf("%d", &value2);

    printf("Первое: ");
    BinInt binValue1 = toBinInt(value1);
    printBinInt(binValue1);
    printf(" = %d\n", fromBinInt(binValue1));

    printf("Второе: ");
    BinInt binValue2 = toBinInt(value2);
    printBinInt(binValue2);
    printf(" = %d\n", fromBinInt(binValue2));

    printf("Сумма:  ");
    BinInt binSumm = summBinInts(binValue1, binValue2);
    printBinInt(binSumm);
    printf(" = %d\n", fromBinInt(binSumm));

    return 0;
}