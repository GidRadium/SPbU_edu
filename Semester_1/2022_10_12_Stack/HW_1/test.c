#include "calculate.h"

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool result = true;

    result &= (calculate("9 6 - 1 2 + *", NULL) == 9);
    result &= (calculate("1 2 +", NULL) == 3);
    result &= (calculate("1 2 *", NULL) == 2);
    result &= (calculate("1 2 -", NULL) == -1);
    result &= (calculate("1 2 /", NULL) == 0);
    result &= (calculate("1 2 + 3 - 100 *", NULL) == 0);

    printf(result ? "All tests passed!\n" : "Tests failed!\n");

    return (int)result - 1;
}