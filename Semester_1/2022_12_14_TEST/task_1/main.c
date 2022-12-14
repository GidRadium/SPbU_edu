#include <stdio.h>

#include "getIntStr.h"

int main(void) {
    char buffer[50] = {0};
    printf("Enter binary int:\n");
    scanf("%s", buffer);
    char *result = getIntStr(buffer);
    if (result == NULL) {
        printf("ERROR!\n");
        return -1;
    }

    printf("Answer is: %s", result);
    free(result);
}
