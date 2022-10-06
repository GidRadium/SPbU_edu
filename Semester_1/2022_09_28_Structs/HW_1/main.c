#include <stdio.h>
#include "BinInt.h"

int main(void) {

    BinInt bi1 = toBinInt(1);
    printBinInt(bi1);
    printf("\n");

    BinInt bi2 = toBinInt(3);
    printBinInt(bi2);
    printf("\n");

    BinInt bi3 = summBinInts(bi1, bi2);
    printBinInt(bi3);
    printf("\n");
    
    printf("%d\n", fromBinInt(bi3));

    printf("\n");
}