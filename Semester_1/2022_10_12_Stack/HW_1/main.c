#include "calculate.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("Enter postfix arithmetic expression (up to 200 symbols):\n");
    char inputString[200];
    scanf("%s", inputString);

    int errorCode = 0;
    int answer = calculate(inputString, &errorCode);

    if (errorCode != 0) {
        printf("ERROR! Error code %d.\n", errorCode);
    } else {
        printf("Answer is %d\n", answer);
    }

    return 0;
}
