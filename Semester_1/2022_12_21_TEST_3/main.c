#include <stdio.h>

#include "checkString.h"

int main(void) {
    printf("Enter string (less than 200 symbols):\n");
    char string[200];
    scanf("%s", string);
    bool result = checkString(string);
    printf("%s\n", (result ? "String is correct!" : "String is NOT correct!"));
    return;
}
