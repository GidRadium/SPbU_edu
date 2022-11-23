#include "polyChecker.h"

#include <stdio.h>

int main(void) {
    printf("Testsing... ");
    int errorCode1 = 0;
    int errorCode2 = 0;
    if (isPolyndrom("ololo.txt", &errorCode1) && errorCode1 == 0
        && !isPolyndrom("ololo2.txt", &errorCode2) && errorCode2 == 0) {
            printf("Done!\n");
    } else {
        printf("ERROR!\n");
        return -1;
    }

    return 0;
}
